#include <stdio.h>
#include <stdlib.h>

char get_first(void);
int get_int(void);

int main()
{
    int n, i;
    char ch;
    n=get_int();
    for (i=1; i <= n; i++) printf("%d\n", i);
    ch=get_first();
    //while((ch>'a' || ch<'p') && ch != 'q') {
    //    ch=get_first();
    //}
    printf("%c\n", ch);
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

int get_int(void)
{
    int input;
    char ch;
    while(scanf("%d", &input) != 1) {
        while((ch=getchar()) != '\n') {
            putchar(ch);
            printf(" is not an integer.\nPlease enter an integer value, such as 25, -178, or 3:\n");
        }
    }
    return input;
}
