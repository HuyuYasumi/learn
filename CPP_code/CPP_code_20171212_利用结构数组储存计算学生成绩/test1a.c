#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test1a.h"

#define BUFSIZE 4096
#define SLEN  81

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

char * s_strchr(char * st, char * str, int m, int n)
{
    char * p;
    int i=0;
    int j=0;
    for (; i<m; i++) {
        j=0;
        if (st[i] == str[j]) {
            p=(st+i);
            int num=i;
            do {
                num++;
                j++;
            } while(j<n && st[num] == str[j]);
            if(j == n) {
                return p;
            }
        }
    }
    return NULL;
}
