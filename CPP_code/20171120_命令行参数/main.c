#include <stdio.h>
#include <stdlib.h>

void pf(char * p[], int n);

int main(int argc, char * argv[])
{
    int count;
    pf(argv, argc);
    printf("The command line has %d arguments:\n", argc-2);
    for (count=2; count<argc; count++) {
        printf("%d: %s\n", count, argv[count]);
    }
    printf("\n");
    return 0;
}

void pf(char * p[], int n)
{
    for(int i=2; i<n; i++) {
        printf("%s ", *(p+i));
    }
    printf("\n");
}
