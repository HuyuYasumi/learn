#include <stdio.h>
#include <stdlib.h>

int to_base_n(int d, int f);
int get_int(void);
int get_int_a(void);

int main()
{
    int a, b;
    printf("Base to ?\n");
    b=get_int();
    printf("Num is ?\n");
    a=get_int_a();
    printf("The new num is ");
    to_base_n(a, b);
    return 0;
}

int to_base_n(int d, int f)
{
    int a, b;
    if(f == 1) {
        printf("%d", d);
    } else {
        a=d/f;
        b=d%f;
        if(d>=f) {
            to_base_n(a, f);
        }
        if(b<=10) {
            printf("%d", b);
        } else {
            printf("%x", b);
        }
    }
    return d;
}

int get_int(void)
{
    int input, i;
    char ch;
    do {
        i=scanf("%d", &input);
        if(i != 1) {
            while((ch=getchar()) != '\n') {
                putchar(ch);
                printf(" is not an integer.\nPlease enter an integer value form 1 to 10 or 16:\n");
            }
        }
        else if(input<1 || (input>10 && input != 16)) {
            printf("%d is out of range.\nPlease enter an integer value form 1 to 10 or 16:\n", input);
        }
    }while(input<1 || (input>10 && input != 16));
    return input;
}

int get_int_a(void)
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
