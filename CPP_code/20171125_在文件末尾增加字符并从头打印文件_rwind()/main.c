#include <ctype.h>
#include <time.h>
#include "test1a.h"

#define STLEN 10
#define WLEN 80
#define TEN 41

int main(int argc, char * argv[])
{
    FILE * fp;
    char words[TEN];
    if((fp=fopen(argv[1], "a+")) == NULL) {
        fprintf(stdout, "Cant't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }
    while((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#')) {
        fprintf(fp, "%s\n", words);
    }
    puts("File contents:");
    rewind(fp);    //返回fp指向文件的最开始
    while(fscanf(fp, "%s", words) == 1) {
        puts(words);
    }
    puts("Done!");
    if(fclose(fp) != 0) {
        fprintf(stderr, "Error closing file\n");
    }
    return 0;
}
