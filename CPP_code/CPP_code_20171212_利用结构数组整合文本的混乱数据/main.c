#include <stdio.h>
#include <stdlib.h>
#define MAXBALL 10
#define DEBUG
struct man {
    int a;
    char fname[10];
    char lname[10];
    int b;
    float c;
    float d;
    float e;
};

int main()
{
    struct man ball[MAXBALL];
    //struct man temp1, temp2;
    //long pos=0;
    int count=1, count2=0, bcount=0, count3=0;
    float ba, ca;
    FILE * pbook;

    if((pbook=fopen("ball.txt", "r+")) == NULL) {
        fputs("Can't open ball.txt file\n", stderr);
        exit(1);
    }
    rewind(pbook);
    while(bcount<10 && fscanf(pbook, "%d %s %s %d %f %f %f", &ball[bcount].a, &ball[bcount].fname, &ball[bcount].lname, &ball[bcount].b, &ball[bcount].c, &ball[bcount].d, &ball[bcount].e) == 7) {
        printf("%s %d %.2f %.2f %.2f\n", ball[bcount].fname, ball[bcount].b, ball[bcount].c, ball[bcount].d, ball[bcount].e);
        bcount++;
    }

    count=bcount;
    //printf("%d", bcount);
    #if defined(DEBUG)
    puts("");
    #endif // defined
    for(int i=0; i<--bcount; i++) {
        for(int i=0, n=1; i<bcount; i++) {
            if(i == (bcount-n)) {
                break;
            }
            if(ball[bcount].a == ball[i].a) {
                struct man temp;
                temp=ball[i];
                ball[i]=ball[bcount-n];
                ball[bcount-n]=temp;
                #if defined(DEBUG)
                printf("%s %d   ", ball[bcount-n].fname, ball[bcount-n].b);
                #endif
                count2++;
                n++;
            }
        }
        #if defined(DEBUG)
        puts("");
        #endif // defined
    }
    #if defined(DEBUG)
    puts("");
    for(int i=0; i<count; i++) {
        printf("%s %d %.2f %.2f %.2f\n", ball[i].fname, ball[i].b, ball[i].c, ball[i].d, ball[i].e);
    }
    #endif // defined

    puts("");
    for(int i=1; i<=count2+1; i++) {
        ba=ball[count3].b;
        ca=ball[count3].c;
        int x=1;
        while(ball[count3].a == ball[count3+1].a) {
            ba+=ball[count3+1].b;
            ca+=ball[count3+1].c;
            count3++;
        }
        printf("The player %s is %.2f\n", ball[count3++].fname, ca/ba);
    }
    fclose(pbook);
    return 0;
}
