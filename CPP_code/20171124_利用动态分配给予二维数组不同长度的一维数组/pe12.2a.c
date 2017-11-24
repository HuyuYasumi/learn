#include "pe12.2a.h"
#define SIZE 15

int * make_array(int elem, int val)
{
    int * marray;
    //printf("%d %d\n", elem, val);
    marray=(int *)malloc(elem*sizeof(int));
    for(int i=0; i<elem; i++) {
        *(marray+i)=val;
    }
    //printf("%u\n", marray);
    return marray;
}

void show_array(const int * ar, int n)
{
    for(int i=0; i<n; i++) {
        printf("%d ", *(ar+i));
    }
}

void make_array2(void)
{
    int j;
    printf("How many words do you wish to enter? ");
    printf("(Enter q to quit) ");
    while(scanf("%d", &j) == 1) {
        char * arr[j];
        char * str;
        printf("Enter %d words now:\n", j);
        for(int i=0; i<j; i++) {
            str=(char *)malloc(SIZE*sizeof(char));
            int n=0;
            char ch;
            do {
                if((ch=getchar()) != ' ' && ch != '\n') {
                    str[n]=ch;
                    n++;
                }
            } while (ch == ' ' || ch == '\n');
            while((str[n]=getchar()) != ' ' && str[n] != '\t' && str[n] != '\n' && str[n] != EOF) {
                n++;
            }
            if(str[n] == ' ' || str[n] == '\n' || str[n] == '\t' || str[n] == EOF) {
                str[n]='\0';
            }
            arr[i]=(char *)malloc((strlen(str)+1)*sizeof(char));
            //printf("%d\n", strlen(str));
            for(int m=0; m<(strlen(str)+1); m++) {
                arr[i][m]=str[m];
            }
            free(str);
        }
        printf("Here are your words:\n");
        for(int i=0; i<j; i++) {
                puts(arr[i]);
                //printf("%d\n", strlen(arr[i]));
                free(arr[i]);
        }
        printf("How many words do you wish to enter? ");
        printf("(Enter q to quit) ");
    }
}
