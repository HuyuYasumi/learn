#ifndef PE12_2A_H_INCLUDED

#define BUFSIZE 4096
#define SLEN  81
#define MAXTITL  40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void add_data(int * count, struct book library[MAXBKS]);
int delete_data(int count, struct book library[MAXBKS]);
void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);
void show_title(int count, struct book library[MAXBKS]);
void show_value(int count, struct book library[MAXBKS]);

#endif // PE12_2A_H_INCLUDED
