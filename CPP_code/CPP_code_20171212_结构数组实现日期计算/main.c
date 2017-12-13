#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test1a.h"
#define MAXTITL  40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);
struct month {
    char month[MAXBKS];
    char mon[MAXBKS];
    int mnum;
    int dnum;
};

void append(FILE * source, FILE * dest);

int main(int argc, char * argv[])
{
    struct month months[12] = { { "January", "jan", 31, 1 }, { "February", "feb", 28, 2 }, { "March", "mar", 31, 3 }, { "April", "apr", 30, 4 }, { "May", "may", 31, 5 }, { "June", "jun", 30, 6 }, { "July", "jul", 31, 7 }, { "August", "aug", 31, 8 }, { "September", "sep", 30, 9  }, { "October", "oct", 31, 10 }, { "November", "nov", 30, 11 }, { "December", "dec", 31, 12 } };
    int count=0, index=0;
    char str[MAXBKS];
    int dm,mm;

    printf("Please enter month:");
    if(scanf("%d", &mm) != 1) {
        s_gets(str, MAXBKS);
        while(strcmp(str, months[count].month) != 0 && strcmp(str, months[count].mon) != 0 && count<12) count++;
    } else count=mm-1;
    printf("Please enter day:");
    scanf("%d", &dm);

    for(int n=0; n<count; n++) {
        index += months[n].mnum;
    }
    printf("%d days", index+dm);
    return 0;
}


