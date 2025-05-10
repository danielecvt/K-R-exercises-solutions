#include <stdio.h>
#define MAXLINE 100

int fgetline (int line[]);
int putline (int line[], int lenght);
int lastchar (int line[], int lenght);


int main(){
    int line[MAXLINE], len;
    while((len = fgetline(line)) > 0)
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
        line[len] = '\n';
        ++len;
        line[len] = '\0';
        ++len;
    }
    return len;
}

int putline(int line[], int len){
    //recall that a sting is made like this: [h,e,l,l,o,\n,\0]
    if (line[len - 3] == ' ')
        len = lastchar(line, len);
    for (int i = 0; i < len; ++i){
        if(line[i] != '\t' && line[0] != '\n')
            putchar(line[i]);
    }
    return 0;
}

int lastchar(int line[], int len){
    int i = len - 3;
    for( ;line[i] == ' '; --i)
        ;
    return i;
}
