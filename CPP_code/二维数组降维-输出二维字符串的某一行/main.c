#include <stdio.h>
#include <stdlib.h>

int main()
{
    int str[4][2]={
        (1,2),
        (3,4),
        (5,6),
        (7,8)
    };
    /*for(int i=0; i <= 4; i++) {
        gets(str[i]);
        printf("%s",str);
    }*/
    pr_row(0,2,(int *)str);
    return 0;
}

void pr_row(int j, int row_dimension, int *p)
{
    int t;
    p=p+(j*row_dimension);
    for(t=0; t<row_dimension; t++) printf("%d,%d,%d,%d\n",*(p+t),t,(int)p+t,p+t);
}
