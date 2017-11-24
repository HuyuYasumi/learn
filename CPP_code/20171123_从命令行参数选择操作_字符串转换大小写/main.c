#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STLEN 10
#define WLEN 80
#define TEN 41

int main(int argc, char * argv[])
{
    /*for(int i=0; i<argc; i++) {
        puts(argv[i]);
    }
    printf("%d\n", argc);*/
    char ch[100];
    int i=0;
    int j=0;
    while((ch[i]=getchar()) != EOF) {
        //printf("%d\n", i);
        i++;
    }
    if(ch[i] == EOF) {
        ch[i]='\0';
    }
    if(argc>1) {
        if(argv[1][1] == 'u') {
            j=0;
            while (ch[j]) {
                ch[j]=toupper(ch[j]);
                j++;
            }
            puts(ch);
        } else if(argv[1][1] == 'l') {
            j=0;
            while (ch[j]) {
                ch[j]=tolower(ch[j]);
                j++;
            }
            puts(ch);
        } else {
            puts(ch);
        }
    } else {
        puts(ch);
        /*for(int m=0; m<strlen(ch); m++){
            printf("%c", ch[m]);
        }*/
    }
    return 0;
}
