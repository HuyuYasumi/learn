#include <stdio.h>
#include <string.h>
#define STLEN 10
#define WLEN 80

int c_gets(char * st, int n);
char * s_strchr(char * st, char * str, int m, int n);   //查找st中第一个与str匹配的字符串并返回首元素的指针

int main()
{
    char words[STLEN];
    char w[WLEN]="abcdefghijklmndefrghijwxyz";
    char * p;
    int num;
    num=c_gets(words, STLEN);
    p=s_strchr(w, words, strlen(w), num);
    if(p != NULL) {
        printf("%d \n",p-w+1);
        for(int i=0; i<num; i++) {
            printf("%c", *(p+i));
        }
        printf("\n");
    }
    return 0;
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

char * s_strchr(char * st, char * str, int m, int n)
{
    char * p;
    int i=0;
    int j=0;
    for (; i<m; i++) {
        j=0;
        if (st[i] == str[j]) {
            p=(st+i);
            int num=i;
            do {
                num++;
                j++;
            } while(j<n && st[num] == str[j]);
            if(j == n) {
                return p;
            }
        }
    }
    return NULL;
}
