#include "test1a.h"
#define SIZE 15

void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while((bytes=fread(temp, sizeof(char), BUFSIZE, source)) >0 ) {
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val=fgets(st, n, stdin);
    if(ret_val) {
        find=strchr(st, '\n');
        if(find) {
            *find='\0';
        } else {
            while(getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

void s_ch_file(char ch, int x, char str[][TEN])
{
    char c;
    FILE * p[STLEN];
    char temp[BUFSIZE];
    for(int j=0; j<x; j++) {
        int i=0;
        printf("%s:\n\n", *(str+j));
        if((p[j]=fopen(str[j], "r+")) == NULL) {
            fprintf(stderr, "Could not open %s for output.\n", str[j]);
            break;
        }
        while(fgets(temp, BUFSIZE, p[j]) != NULL) {
            for(int n=0; (c=temp[n]) != '\0'; n++){
                if(c == ch){
                    i++;
                }
                putchar(c);
            };
        }
        printf("\n\nThere are %d %c in %s.\n\n", i, ch, *(str+j));
    }
}

void s_ch_file2(char ch, int x, char * str[])
{
    char c;
    FILE * p[STLEN];
    char temp[BUFSIZE];
    for(int j=2,m=0; j<x; j++) {
        int i=0;
        printf("%s:\n\n", *(str+j));
        if((p[m]=fopen(*(str+j), "r+")) == NULL) {
            fprintf(stderr, "Could not open %s for output.\n", *(str+j));
            break;
        }
        while(fgets(temp, BUFSIZE, p[m]) != NULL) {
            for(int n=0; (c=temp[n]) != '\0'; n++){
                if(c == ch){
                    i++;
                }
                putchar(c);
            };
        }
        printf("\n\nThere are %d %c in %s.\n\n", i, ch, *(str+j));
        m++;
    }
}
