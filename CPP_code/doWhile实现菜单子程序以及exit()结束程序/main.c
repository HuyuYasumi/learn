#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    for(;;) {
        do{
        printf("1.First\n");
        printf("2.Twice\n");
        printf("3.Second\n");
        printf("4.Quit\n");
        printf("  Enter your choice\n");
        ch=getchar();
        }while(ch != '1' && ch != '2' && ch !='3' && ch != '4');
        switch(ch) {
            case '1':
                printf("A\n");
                break;
            case '2':
                printf("B\n");
                break;
            case '3':
                printf("C\n");
                break;
            case '4':
                exit(0);
        }
        while(getchar() != '\n') continue;
    }
    return 0;
}
