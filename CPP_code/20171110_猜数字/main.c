#include <stdio.h>
#include <stdlib.h>

char get_first(void);

int main()
{
    float num, p=50000;
    char ch;
    float i=0,n=100000;
    printf("Please enter a num form 1 ~ 100000:\n");
    scanf("%lf", &num);
    do {
        printf("Is the num %.0f? ((b)iger or (s)maller or (y)es)\n", p);
        ch=get_first();
        switch(ch) {
            case 'b':
                i <= n ? (n=p, p = (p+=i)/2) : (i=p, p = (p+=n)/2);
                break;
            case 's':
                i <= n ? (i=p, p = (p+=n)/2) : (n=p, p = (p+=i)/2);
                break;
        }
    } while(ch != 'y' || p == num);
    printf("Oh, I get it. It's %.0f.\n", p);
    return 0;
}

char get_first(void)
{
    char ch;
    ch=getchar();
    while(ch == '\n' || ch == ' ') ch=getchar();
    while(getchar() != '\n') continue;
    return ch;
}
