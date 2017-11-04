#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("1.First\n");
    printf("2.Twice\n");
    printf("3.Second\n");
    printf("4.Quit\n");
    printf("  Enter your choice\n");

    do {
        ch=getchar();
        switch(ch) {
            case '1':
                printf("A");
                break;
            case '2':
                printf("B");
                break;
            case '3':
                printf("C");
            case '4':
                exit(0);
        }
    } while(ch != '1' && ch != '2');
    return 0;
}
