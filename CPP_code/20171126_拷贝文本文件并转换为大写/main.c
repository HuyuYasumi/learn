#include <ctype.h>
#include <time.h>
#include "test1a.h"
#define STLEN  10
#define WLEN  80
#define TEN  41
#define ARSIZE 1000

void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{
    char numbers[TEN];
    FILE * iofile, * iofsrc;

    printf("Please enter filename:\n");
    while(s_gets(numbers, TEN) && numbers[0] != '\0') {
        char str[TEN]="cpry_";
        char temp[BUFSIZE];
        if((iofsrc=fopen(numbers, "r")) == NULL) {
            fprintf(stderr, "Could not open %s for output.\n", numbers);
            exit(EXIT_FAILURE);
        }
        if(setvbuf(iofsrc, NULL, _IOFBF, BUFSIZE) != 0) {
            fputs("Can't create output buffer\n",  stderr);
            exit(EXIT_FAILURE);
        }
        strcat(str, numbers);
        if((iofile=fopen(str, "w")) == NULL) {
            fprintf(stderr, "Could not open %s for output.\n", str);
            exit(EXIT_FAILURE);
        }
        if(setvbuf(iofile, NULL, _IOFBF, BUFSIZE) != 0) {
            fputs("Can't create output buffer\n",  stderr);
            exit(EXIT_FAILURE);
        }
        size_t times;
        while((times=fread(temp, sizeof(char), BUFSIZE, iofsrc)) > 0) {
            //printf("%d\n",times);
            int n=0;
            for(int i=0+n*BUFSIZE; i<times; i++) {
                temp[i]=toupper(temp[i]);
                putchar(temp[i]);
            }
            putchar('\n');
            fwrite(temp, sizeof(char), times, iofile);
            n++;
            //puts("O");
        }
        //append(iofsrc, iofile);
        fseek(iofile, 0, SEEK_SET);
        //rewind(iofile);
        /*char ch;
        while((ch=getc(iofile)) != EOF) {
            putchar(ch);
        }*/
        fclose(iofsrc);
        fclose(iofile);
    }
    puts("Bye!");
    return 0;
}
