#include <ctype.h>
#include <time.h>
#include "test1a.h"
#define STLEN  10
#define WLEN  80
#define TEN  41
#define ARSIZE 1000

void append(FILE * source, FILE * dest);
char * s_gets(char * st, int n);

int main(int argc, char * argv[])
{
    double numbers[ARSIZE];
    double value;   // 存放指定读出的数据的变量
    const char * file="numbers.dat";    // 用于创建二进制文件名字的指针
    int i;
    long pos;   // 存放指定读出的数据的位置的变量
    FILE * iofile;

    for(i=0; i<ARSIZE; i++) {
        numbers[i]=100.0*i+1.0/(i+1);
    }

    if((iofile=fopen(file, "wb")) == NULL) {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }

    fwrite(numbers, sizeof(double), ARSIZE, iofile);
    fclose(iofile);
    if((iofile=fopen(file, "rb")) == NULL) {
        fprintf(stderr, "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }

    printf("Enter an index in the range 0-%d.\n", ARSIZE-1);
    while(scanf("%d", &i) == 1 && i >= 0 && i<ARSIZE) {
        pos=(long)i*sizeof(double);
        fseek(iofile, pos, SEEK_SET);
        fread(&value, sizeof(double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    fclose(iofile);
    puts("Bye!");
    return 0;
}
