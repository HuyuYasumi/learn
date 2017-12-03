#include <ctype.h>
#include <time.h>
#include "test1a.h"
#define WLEN  80
#define ARSIZE 1000

void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{

    char str[STLEN][TEN];
    char c,ch;
    char tcl;
    char tc;
    int x=0;
    switch(argc) {
        case 1:
            printf("Please enter char and files: ");
            c=getchar();
            getchar();
            for(int j=0; (ch=getchar()) != '\n'; j++) {
                str[j][0]=ch;
                int i=1;
                for(; (ch=getchar()) != ' '; i++) {
                    if(ch =='\n') {
                        break;
                    }
                    str[j][i]=ch;
                }
                str[j][i]='\0';
                x++;
                if(ch == '\n') {
                    break;
                }
            }
            s_ch_file(c, x, str);
            break;
        case 2:
            tc=argv[1][0];
            printf("Please enter files: ");
            for(int j=0; (ch=getchar()) != '\n'; j++) {
                str[j][0]=ch;
                int i=1;
                for(; (ch=getchar()) != ' '; i++) {
                    if(ch =='\n') {
                        break;
                    }
                    str[j][i]=ch;
                }
                str[j][i]='\0';
                x++;
                if(ch == '\n') {
                    break;
                }
            }
            s_ch_file(tc, x, str);
            break;
        default:
            tcl=argv[1][0];
            s_ch_file2(tcl, argc, argv);
            break;
    }
    return 0;
}


