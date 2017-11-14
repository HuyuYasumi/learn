#include <stdio.h>

void pf(int * p, int n);
void pf_two(int i, int j, int arrs[i][j]);
int rmax(int * p, int n);
int rmin(int * p, int n);
void copy_two(int i, int j, int arr[i][j], int arrs[i][j]);
void copy_arr(int tg[], int sr[], int n);
void copy_ptr(int * ptg, int * psr, int n);
void copy_ptrs(int * ptg, int * psr, int * n);

int main()
{
    int sr[5]={46, 4320, 8, 963, 5};
    int srtwo[5][5];
    int srtwos[2][3]={{2, 4, 6}, {2, 5, 10}};
    int srtwoss[2][3];
    int srtwosss[2][3];
    int three[3];
    int tg1[5];
    int tg2[5];
    int tg3[5];
    int min, max;

    min=rmin(sr, 5);
    max=rmax(sr, 5);
    copy_two(2, 3, srtwosss, srtwos);
    copy_arr(tg1, sr, 5);
    copy_ptr(tg2, sr, 5);
    copy_ptr(srtwo[0], sr, 5);
    copy_ptr(three, sr+2, 5);
    copy_ptrs(tg3, sr, sr+5);

    printf("%d %d\n", min, max);
    pf(three, 3);
    pf_two(2, 3, srtwos);
    pf_two(2, 3, srtwosss);
    for(int n=0; n<5; n++) {
        printf("%d %d %d %d %d\n", sr[n], tg1[n], tg2[n], tg3[n], srtwo[0][n]);
    }
    return 0;
}

void pf(int * p, int n)
{
    for(int i=0; i<n; i++) {
        printf("%d ", *(p+i));
    }
    printf("\n");
}

void pf_two(int i, int j, int arrs[i][j])
{
    for(int x=0; x<i; x++) {
        for(int y=0; y<j; y++) {
            printf("%d ",arrs[x][y]);
        }
        printf("\n");
    }
}

void copy_arr(int tg[], int sr[], int n)
{
    for(int i=0; i<n; i++) {
        tg[i]=sr[i];
    }
}

void copy_ptr(int * ptg, int * psr, int n)
{
    for(int i=0; i<n; i++) {
        (*(ptg+i))=(*(psr+i));
    }
}

void copy_ptrs(int * ptg, int * psr, int * n)
{
    for(; psr<n; psr++, ptg++) {
        *(ptg)=*(psr);
    }
}

int rmax(int * p, int n)
{
    int ct=*p, x=0;
    for(int i=0; i<(n-1); i++) {
        if(ct<*(p+i+1)) {
            ct=*(p+i+1);
            x=i+1;
        }
    }
    return x;
}

int rmin(int * p, int n)
{
    int ct=*p;
    for(int i=0; i<(n-1); i++) {
        if(ct>*(p+i+1)) {
            ct=*(p+i+1);
        }
    }
    return ct;
}

void copy_two(int i, int j, int arr[i][j], int arrs[i][j])
{
    for(int x=0; x<i; x++) {
        for(int y=0; y<j; y++) {
            arr[x][y]=arrs[x][y];
            printf("%d %d\n", x, y);
        }
    }
}
