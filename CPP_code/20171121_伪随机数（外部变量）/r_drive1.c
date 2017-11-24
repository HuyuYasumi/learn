#include <stdio.h>
#include <stdlib.h>
#include "roll.h"

extern int nb[10];

int main(void)
{
    int count;
    unsigned seed;
    printf("Please enter your choice for seed.\n");
    while(scanf("%u", &seed) == 1) {
        srand1(seed);
        for(count=0; count<1000; count++) {
            unsigned num;
            num=rand1()%10+1;
            one_ten(num);
            if(count<10) {
                printf("%d ", num);
            }
        }
        printf("\n");
        for(int i=0; i<10; i++) {
            printf("%d ", nb[i]);
            nb[i]=0;
        }
        printf("\nPlease enter next seed (q to quit):\n");
    }
    printf("Done\n");
    return 0;
}
