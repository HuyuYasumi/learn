#ifndef TEST1A_H_INCLUDED
#define TEST1A_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LEFT 0
#define CENTER 1
#define RIGHT 2
#define ONEL printf("   ID  SIZE ALIGNMENT  B   I   U \n")
#define CHOOSE printf("f)change font     s)change size     a)change alignment\nb)toggle bold     i)toggle italic   u)toggle underline\nq)quit\n")

struct font {
    unsigned int id:8;
    unsigned int size:7;
    unsigned int al:2;
    bool bold:1;
    bool it:1;
    bool un:1;
};

void show_font(const struct font * pf);

#endif // PE12_2A_H_INCLUDED
