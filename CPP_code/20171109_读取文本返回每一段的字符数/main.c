#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch;
    int x[100];
    int *p;
    int i=1;
    p=x;
    *p=0;
    for(; (ch=getchar()) != EOF;) {
        putchar(ch);
        if(ch == ' ' || ch == '\n' || ch == '\t') {
            p++;
            *p=0;
            i++;
        } else (*p)++;
    }
    printf("\n");
    for(int n=0; n < i; n++) {
        p=x;
        printf("%d ", *(p+n));
    }
    return 0;
}
