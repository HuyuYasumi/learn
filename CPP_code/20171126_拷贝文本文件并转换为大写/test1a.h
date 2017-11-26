#ifndef PE12_2A_H_INCLUDED
#define PE12_2A_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN  81

void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);

#endif // PE12_2A_H_INCLUDED
