#include <stdio.h>
#define MAXLINE 100

int fgetline (int line[]);
int putline (int line[], int lenght);


int main(){
    int line[MAXLINE], len;
    while((len = fgetline(line)) > 0)
        if(len > 80)
            putline(line, len);
    return 0;
}

int fgetline (int line[]){
    int c, len = 0;
    for(int i = 0;((c = getchar()) != '\n') && i < MAXLINE - 1 && c != EOF; ++i){
        line[i] = c;
        ++len;
    }
    if (c != EOF){
        line[len] = '\0';
        ++len;
    }
    return len;
}

int putline(int line[], int len){
    for (int i = 0; i < len; ++i)
        putchar(line[i]);
    return 0;
}
