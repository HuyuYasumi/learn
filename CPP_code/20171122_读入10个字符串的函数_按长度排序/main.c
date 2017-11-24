#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STLEN 10
#define WLEN 80
#define TEN 41

char ten_gets(int n, char st[10][n]);    //读入10个字符串或读到EOF停止
void str_max_int(int n, int m, char st[n][m]);    //按字符串长度排序
void py_str_two(int n, int m, char st[n][m]);    //打印二维字符串
void str_max_first(int n, int m, char st[n][m]);    //按第一个单词长度排序

int main()
{
    char str[10][TEN];
    int num;
    ten_gets(TEN, str);
    for(;;) {
        printf("Please enter 1~5.(0 is quiet)\n");
        printf("1.直接打印    2.以ASCII排序    3.按长度排序\n");
        printf("4.按第一个单词长度    5.退出\n");
        scanf("%d", &num);
        switch (num) {
            case 1:
                py_str_two(10, TEN, str);
                break;
            case 2:
                break;
            case 3:
                str_max_int(10, TEN, str);
                break;
            case 4:
                str_max_first(10, TEN, str);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}

char ten_gets(int n, char st[10][n])
{
    int i=0;
    int j;
    char ch;
    for(; i<10; i++) {
        do {
            if((ch=getchar()) != '\n' && ch != '\t' && ch !=' ' && ch != EOF) {
                st[i][0]=ch;
            } else if(ch == EOF) {
                exit(0);
            }
        } while (ch == '\n' || ch == '\t' || ch == ' ');
        j=0;
        do {
            j++;
            if((st[i][j]=getchar()) == '\n') {
                st[i][j]='\0';
                break;
            } else if(st[i][j] == EOF) {
                exit(0);
            }
        } while (j<(n-2));
        st[i][j+1]='\0';
    }
    return 'd';
}

void str_max_int(int n, int m, char st[n][m])
{
    char str[n][m];
    for(int i=0; i<n; i++) {
        strcpy(str[i], st[i]);
    }
    for(int x=0,y=0; x<(n-1); x++) {
        y=n-1;
        for(; y>x; y--) {
            if(strlen(str[x]) < strlen(str[y])) {
                char tem[m];
                strcpy(tem, str[x]);
                strcpy(str[x], str[y]);
                strcpy(str[y], tem);
            }
        }
    }
    py_str_two(n, m, str);
}

void py_str_two(int n, int m, char st[n][m])
{
    for(int i=0; i<n; i++) {
        puts(st+i);
    }
}

void str_max_first(int n, int m, char st[n][m])
{
    char str[n][m];
    int i=0;
    int j=0;
    for(; i<n; i++) {
        j=0;
        while(st[i][j] != '\t' && st[i][j] != ' ') {
            str[i][j]=st[i][j];
            j++;
        }
        if(st[i][j] == '\t' || st[i][j] == ' ') {
            str[i][j]='\0';
        }
    }
    for(int x=0,y=0; x<(n-1); x++) {
        y=n-1;
        for(; y>x; y--) {
            if(strlen(str[x]) < strlen(str[y])) {
                char tem[m];
                strcpy(tem, str[x]);
                strcpy(str[x], str[y]);
                strcpy(str[y], tem);
            }
        }
    }
    py_str_two(n, m, str);
}
