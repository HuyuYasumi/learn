#include <stdio.h>
#include <string.h>
#define STLEN 10

void ss_gets(char * st, int n);
int c_gets(char * st, int n);   //清除前后的空字符制表符换行符并返回st字符串的字符数

int main()
{
    char words[STLEN];
    c_gets(words, STLEN);
    fputs(words, stdout);
    return 0;
}

void ss_gets(char * st, int n)
{
    char str[80];
    c_gets(str, 80);
    strncpy(st, str, n-1);
}

int c_gets(char * st, int n)
{
    char ch;
    int i=1;
    int num=1;
    do {
        if((ch=getchar()) != '\n' && ch != '\t' && ch !=' ') {
            st[0]=ch;
        }
    } while (ch == '\n' || ch == '\t' || ch == ' ');
    if(fgets(st+1, n-1, stdin)) {
        while(st[i] != '\n' && st[i] != '\0') {
            i++;
            num=i;
        }
        if(st[i] == '\n') {
            st[i]='\0';
        } else {
            while(getchar() != '\n') {
                continue;
            }
        }
    }
    return num;
}
