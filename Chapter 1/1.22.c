#include <stdio.h>

#define MAXLINE 100

int fgetline(int line[]);
int printline(int line[],int start, int stop);
int split(int line[], int len, int tablen);
int getn();
int lastcharpos(int line[], int len);

int main(){
    int line[MAXLINE], len, n;
    n = getn();
    while((len = fgetline(line)) > 0)
        split(line, len, n);
    return 0;
}

int fgetline (int line[]){
    int c, len = 0;
    printf("Insert the long line, it will be cutted: \n");
    for(int i = 0;((c = getchar()) != '\n') && i < MAXLINE - 1 && c != EOF; ++i){
        line[i] = c;
        ++len;
    }
    
    if (c != EOF){
        line[len] = '\n';
        ++len;
    }

    return len;
}

int printline(int line[],int start, int stop){
    for(int i = start; i < stop; ++i)
        putchar(line[i]);
    putchar('\n');
    return 0;
}

int split(int line[], int len, int n){
    int nsplit = 0, tailchars;
    len = lastcharpos(line, len);
    nsplit = len / n;
    tailchars = len - nsplit * n;
    for (int i = 0; i < nsplit; ++i)
        printline(line, i * n, (i+1)*n);
    for (int i = nsplit * n; i < len; ++i)
        putchar(line[i]);

    return 0;
    }

int getn(){
    int n, end;
    printf("after how many colums do you want to cut? ");
    n = getchar();
    if ((end = getchar()) != '\n')
    putchar('\n');
    return n - '0';
}

int lastcharpos(int line[], int len){
    int lastchar = len; 
    for (int i = len - 1; line[i] == ' '; --i)
        lastchar = i;
    return lastchar;
}