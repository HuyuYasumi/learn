#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char target[80] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

    converge(target,"This is a test of converge().");
    printf("Final string: %s\n",target);
    return 0;
}

void converge(char targ[80],char src[80])
{
    int i,j;

    printf("%s\n",targ);
    for(i=0,j=strlen(src);i <= j;i++,j--) {
        targ[i] = src[i];
        targ[j] = src[j];
        printf("%s\n",targ);
    }
}
