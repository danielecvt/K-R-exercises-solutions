#include <stdio.h>

#define MAXLINE 100

int fgetline(int line[]);
int printline(int line[], int len);
int gettablen();
int entab(int line[], int len, int tablen);

int main(){
    int line[MAXLINE], len, tablen;
    tablen = gettablen();
    while((len = fgetline(line)) > 0){
        len = entab(line, len, tablen);
        printline(line, len);
    }
    return 0;
}

int fgetline (int line[]){
    int c, len = 0;
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

int printline(int line[], int len){
    for(int i = 0; i < len; ++i)
        putchar(line[i]);
    return 0;
}

int gettablen(){
    int c;
    printf("Press tab then insert the number over the insert point\n");
    printf("123456789\n");
    c = getchar();
    c = getchar();
    //the array index start from 0
    return c - '1';

}

int entab(int line[], int len, int tablen){
    int ntab = 0, tailblanks;
    ntab = len / tablen;
    tailblanks = len - ntab * tablen;
    if (tailblanks == tablen)
        ++ntab; 
    for (int i = 0; i < ntab; ++i)
        line[i] = '\t';
    for (int i = ntab; i < ntab + tailblanks; ++i)
        line[i] = ' ';
    return ntab + tailblanks;
}
