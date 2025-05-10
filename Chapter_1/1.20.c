#include <stdio.h>

#define MAXLINE 100

int fgetline(int line[]);
int detab(int line[], int len, int tablen);
int gettablen();


int main(){
    int line[MAXLINE], len, tablen;
    tablen = gettablen();
    while((len = fgetline(line)) > 0)
        detab(line, len, tablen);
    
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

int detab(int line[], int len, int tablen){
    int stamppos = 0, mod, spaces;
    for(int i = 0; i < len; ++i){
        if(line[i] == '\t'){
            // tablen % stamppos = stamppos - ((tablen / stamppos) * tablen)
            mod = stamppos - (stamppos / tablen) * tablen;
            spaces = tablen - mod;
            for(int j = 0; j < spaces; ++j){
                putchar(' ');
                ++stamppos;
                }
        }else{
        putchar(line[i]);
        ++stamppos;
        }
    }
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

