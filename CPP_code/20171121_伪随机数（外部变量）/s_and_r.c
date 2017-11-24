#include <stdio.h>
#include <stdlib.h>
#include "roll.h"

static unsigned long int next=1;    //种子
int nb[10];

int rand1(void)
{
    next=next*1103515245+12345;
    return (unsigned int)(next/65536)%32768;
}

void srand1(unsigned int seed)
{
    next=seed;
}

void one_ten(int num)
{
    switch(num) {
        case 1:
            nb[0]++;
            break;
        case 2:
            nb[1]++;
            break;
        case 3:
            nb[2]++;
            break;
        case 4:
            nb[3]++;
            break;
        case 5:
            nb[4]++;
            break;
        case 6:
            nb[5]++;
            break;
        case 7:
            nb[6]++;
            break;
        case 8:
            nb[7]++;
            break;
        case 9:
            nb[8]++;
            break;
        case 10:
            nb[9]++;
            break;
    }
}
