#include <stdio.h>
#include <stelib.h>

int sqrunm(int num);
int readnum(void);
int prompt(void);

int main()
{
    int t;

    for(prompt();t = readnum();prompt()) {
        sqrnum(t);
    }
    return 0;
}

int prompt (void)
{
    printf("Enter a number:");
    return 0;
}

int readnum(void)
{
    int t;

    scanf("%d",&t);
    return t;
}

int sqrnum(int num)
{
    printf("%d\n",num*num);
    return num*num;
}
