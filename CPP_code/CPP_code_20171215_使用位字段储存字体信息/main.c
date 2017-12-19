#include "test1a.h"

int main(int argc, char * argv[])
{
    struct font fonts[10]={{0, 12, LEFT, false, false, false}};;
    char ch;
    int num=0;
    for(unsigned int i=1; i<10; i++) {
        fonts[i]=fonts[0];
        fonts[i].id=i;
    }
    show_font(&fonts[0]);
    CHOOSE;
    while(scanf("%c", &ch) == 1 && ch != 'q') {
        while(getchar() != '\n');
        switch(ch) {
            case 'f':
                printf("Enter font ID(0~9):");
                scanf("%d", &num);
                while(getchar() != '\n');
                break;
            case 's':
                printf("Enter font size(0~127):");
                unsigned int x;
                scanf("%u", &x);
                while(getchar() != '\n');
                fonts[num].size=x;
                break;
            case 'a':
                printf("Select alignment:\n1)left   c)center   r)right\n");
                scanf("%c", &ch);
                while(getchar() != '\n');
                switch(ch) {
                    case 'l':
                        fonts[num].al=LEFT;
                        break;
                    case 'c':
                        fonts[num].al=CENTER;
                        break;
                    case 'r':
                        fonts[num].al=RIGHT;
                    default:
                        puts("Don't has the mode");
                }
                break;
            case 'b':
                if(fonts[num].bold == false) {
                        fonts[num].bold=true;
                } else fonts[num].bold=false;
                break;
            case 'i':
                if(fonts[num].it == false) {
                        fonts[num].it=true;
                } else fonts[num].it=false;
                break;
            case 'u':
                if(fonts[num].un == false) {
                        fonts[num].un=true;
                } else fonts[num].un=false;
                break;
            case 'q':
                break;
            default:
                puts("Don't has the mode");
        }
        show_font(&fonts[num]);
        CHOOSE;
    }
    puts("Bye!");
    return 0;
}

