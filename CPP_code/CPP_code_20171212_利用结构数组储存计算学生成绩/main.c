#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test1a.h"
#define MAXTITL  40
#define MAXAUTL 40
#define MAXBKS 10

char * s_gets(char * st, int n);
char * s_strchr(char * st, char * str, int m, int n);
struct name {
    char fname[MAXBKS];
    char lname[MAXBKS];
};
struct student {
    struct name thename;
    float grade[3];
    float num;
};

int main(int argc, char * argv[])
{
    struct student thegrade[4]={
        {{"one", "eno"}},
        {{"two", "owt"}},
        {{"three", "eerht"}},
        {{"four", "ruof"}}
    };
    char yourname[MAXBKS*2];
    int n=0;
    printf("Please enter student's name:");
    while(s_gets(yourname, 20) && n<4) {
        int count=0, index=0;
        while(s_strchr(yourname, thegrade[count].thename.fname, strlen(yourname), 3) == NULL && s_strchr(yourname, thegrade[count].thename.lname, strlen(yourname), 3) == NULL) {
            //printf("%s %s\n", thegrade[count].thename.fname, thegrade[count].thename.lname);
            count++;
        }
        //printf("%d\n", count);
        printf("Please enter three number like \"85 95 84\"\n");
        //scanf("%f %f %f", &(thegrade[n].grade[count]), &(thegrade[count].grade[1]), &(thegrade[count].grade[2]));
        for(int i=0; i<3; i++) {
            scanf("%f", &thegrade[count].grade[i]);
            index+=thegrade[count].grade[i];
        }
        while(getchar() != '\n');
        thegrade[count].num=index/3;
        n++;
        if(n != 4) {
            printf("Please enter next student's name:");
        } else break;
    }
    for(int i=0; i<4; i++) {
        printf("\n%s's score are %.2f&%.2f&%.2f.\nThe average score is %.2f.\n", thegrade[i].thename.fname, thegrade[i].grade[0], thegrade[i].grade[1], thegrade[i].grade[2], thegrade[i].num);
    }
    return 0;
}


