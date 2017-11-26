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
