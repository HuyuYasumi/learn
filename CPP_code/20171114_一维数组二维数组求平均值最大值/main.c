#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 2
#define COLS 3

void pf_one(double * p, int n);
void pf_two(int i, int j, double arrs[i][j]);
void get_two(double * p, int n);
double rmax(double * p, int n);
double average_one(double * p, int n);
double average_two(int i, int j, double arrs[i][j]);

int main()
{
    double arr[ROWS][COLS];
    double sa[ROWS];
    double allA;
    double min;
    get_two(arr[0], ROWS*COLS);
    for(int i=0; i<ROWS; i++) {
        sa[i]=average_one(arr[i], COLS);
    }
    allA=average_two(ROWS, COLS, arr);
    min=rmax(arr[0], ROWS*COLS);
    pf_two(ROWS, COLS, arr);
    pf_one(sa, ROWS);
    printf("%.3f\n%.3f\n", allA, min);
    return 0;
}

void pf_one(double * p, int n)
{
    for(int i=0; i<n; i++) {
        printf("%.3f ", *(p+i));
    }
    printf("\n");
}

void pf_two(int i, int j, double arrs[i][j])
{
    for(int x=0; x<i; x++) {
        for(int y=0; y<j; y++) {
            printf("%.3f ",arrs[x][y]);
        }
        printf("\n");
    }
}

void get_two(double * p, int n)
{
    for(int i=0; i<n; i++) {
        scanf("%lf", p+i);
    }
}

double average_one(double * p, int n)
{
    double x=0;
    for(int i=0; i<n; i++) {
        x+=*(p+i);
    }
    return x/n;
}

double average_two(int i, int j, double arrs[i][j])
{
    double n=0;
    for(int x=0; x<i; x++) {
        for(int y=0; y<j; y++) {
            if(arrs[x][y] == 0) {
                printf("Error\n");
                return 0;
            } else {
                n+=arrs[x][y];
            }
        }
    }
    return n/(i*j);
}

double rmax(double  * p, int n)
{
    double ct=*p;
    for(int i=0; i<(n-1); i++) {
        if(ct<*(p+i+1)) {
            ct=*(p+i+1);
        }
    }
    return ct;
}
