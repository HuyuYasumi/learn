#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test1a.h"

int main(int argc, char * argv[])
{
    struct book library[MAXBKS];
    int count=0;
    int index, filecount;
    FILE * pbooks;
    int size=sizeof(struct book);
    int num, num1;

    if((pbooks=fopen("book.dat", "r+b")) == NULL) {
        fputs("Can't open book.dat file\n", stderr);
        exit(1);
    }
    rewind(pbooks);
    while(count<MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if(count == 0) puts("Current contents of book.dat\n");
        printf("%s by %s:$%.2f\n", library[count].title, library[count].author, library[count].value);
        count++;
    }
    puts("");
    filecount=count;

    puts("Please enter 1~3 to choose the Modify Mode:");
    printf("1.add\t2.change\n3.delete\tQ.quit\n");
    while(scanf("%d", &num1) == 1) {
        switch(num1) {
            case 1:
                if(count == MAXBKS) {
                    fputs("The book.dat file is full.\n\n", stderr);
                } else {
                    add_data(&count, library);
                }
                break;
            case 2:
                break;
            case 3:
                //delete_data(count, library);
                break;
        }
        puts("Please enter 1~3 to choose the Modify Mode:");
        printf("1.add\t2.change\n3.delete\tQ.quit\n");
    }

    if(count>0) {
        while(getchar() != '\n');
        rewind(pbooks);
        fwrite(&library[0], size, count, pbooks);
        puts("Please enter 1~3 to choose show mode:");
        printf("1.title\t2.value\n3.normal\tQ.quit\n");
        while(scanf("%d", &num) == 1) {
            puts("Here is the list of your books:");
            switch(num) {
                case 1:
                    show_title(count, library);
                    break;
                case 2:
                    show_value(count, library);
                    break;
                case 3:
                    rewind(pbooks);
                    count=0;
                    puts("");
                    while(count<MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
                        printf("%s by %s:$%.2f\n", library[count].title, library[count].author, library[count].value);
                        count++;
                    }
                    puts("");
                    /*for(index=0; index<count; index++) {
                        printf("%s by %s:$%.2f\n", library[index].title, library[index].author, library[index].value);
                    }*/
                    break;
            }
            puts("Please enter 1~3 to choose show mode:");
            printf("1.title\t2.value\n3.normal\tQ.quit\n");
        }
    } else puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}


