#include <stdio.h>
#define MAXLINE 100

int fgetline(int line[]);
int reverce(int line[], int lenght);


int main(){
    int line[MAXLINE], len;
    while((len = fgetline(line)) > 0)
        reverce(line, len);
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
        line[len] = '\0';
        ++len;
    }
    return len;
}

int reverce(int line[], int len){
    //recall that a sting is made like this: [h,e,l,l,o,\n,\0]
    for (int i = len - 3; i >= 0; --i)
            putchar(line[i]);
    
    return 0;
}

