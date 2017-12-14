#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test1a.h"

void append(FILE * source, FILE * dest)
{
    size_t bytes;
    static char temp[BUFSIZE];
    while((bytes=fread(temp, sizeof(char), BUFSIZE, source)) >0 ) {
        fwrite(temp, sizeof(char), bytes, dest);
    }
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val=fgets(st, n, stdin);
    if(ret_val) {
        find=strchr(st, '\n');
        if(find) {
            *find='\0';
        } else {
            while(getchar() != '\n') {
                continue;
            }
        }
    }
    return ret_val;
}

void show_title(int count, struct book library[MAXBKS])
{
    puts("");
    for(int n=0; n<count-1; n++) {
        for(int m=1; m<count-n; m++) {
            struct book temp;
            if(strcmp(library[n].title, library[m+n].title)>0) {
                temp=library[n];
                library[n]=library[m+n];
                library[m+n]=temp;
            }
        }
        printf("%s by %s:$%.2f\n", library[n].title, library[n].author, library[n].value);
    }
    printf("%s by %s:$%.2f\n", library[count-1].title, library[count-1].author, library[count-1].value);
    puts("");
}

void show_value(int count, struct book library[MAXBKS])
{
    puts("");
    for(int n=0; n<count-1; n++) {
        for(int m=1; m<count-n; m++) {
            struct book temp;
            if(library[n].value>library[n+m].value) {
                temp=library[n];
                library[n]=library[m+n];
                library[m+n]=temp;
            }
        }
        printf("%s by %s:$%.2f\n", library[n].title, library[n].author, library[n].value);
    }
    printf("%s by %s:$%.2f\n", library[count-1].title, library[count-1].author, library[count-1].value);
    puts("");
}

void add_data(int * count, struct book library[MAXBKS])
{
    puts("Please add new book titles.");
    puts("Please [enter] at the start of a line to stop.");
    while(*count<MAXBKS && s_gets(library[*count].title, MAXTITL) != NULL && library[*count].title[0] != '\0') {
        puts("Now enter the author.");
        s_gets(library[*count].author, MAXAUTL);
        puts("Now enter the value.");
        scanf("%f", &library[*count++].value);
        while(getchar() != '\n') continue;
        if(*count<MAXBKS) puts("Enter the next title.");
    }
}

int delete_data(int count, struct book library[MAXBKS])
{
    while(getchar() != '\n');
    char temp[MAXTITL];
    int i=0;
    puts("Please enter the title to delete:");
    s_gets(temp, MAXTITL);
    while(strcmp(temp, library[i].title) != 0 && i<count) {
        i++;
    }
    for(int n=0; n<count-i+1; n++) {
        library[i+n]=library[i+n+1];
    }
    return count-1;
}

