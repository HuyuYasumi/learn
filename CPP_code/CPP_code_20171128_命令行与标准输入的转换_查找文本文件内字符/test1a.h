#ifndef PE12_2A_H_INCLUDED
#define PE12_2A_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN  81
#define STLEN  10
#define TEN  41

void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);
void s_ch_file(char ch, int x, char str[][TEN]);
void s_ch_file2(char ch, int x, char * str[]);

#endif // PE12_2A_H_INCLUDED
