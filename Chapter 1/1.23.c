#include <stdio.h>

#define MAXCODE 1000000

int fgetcode(int code[]);
int printcode(int code[], int len);
int ignorecodecomment(int code[], int start, int len);
int ignoreblockcomment(int code[], int start, int len);

int main(){
    int code[MAXCODE], len, n;
    len = fgetcode(code);
    printcode(code, len);
    return 0;
}

int fgetcode (int code[]){
    int c, len = 0;
    printf("Insert the code, I'll ignore the comments: \n");
    for(int i = 0;((c = getchar()) != EOF) && i < MAXCODE - 1; ++i){
        code[i] = c;
        ++len;
    }
    
    if (c != EOF){
        code[len] = '\n';
        ++len;
    }
    putchar('\n'); //new line after inserted code
    return len;
}


int printcode(int code[], int len){
    for (int i = 0; i < len; i++){
        if ((code[i] == '/' && code[i + 1] == '/'))
            i = ignorecodecomment(code, i, len);
        else if ((code[i] == '/') && (code[i + 1] == '*'))
            i = ignoreblockcomment(code, i, len);
        else 
            putchar(code[i]);
    }
    return 0;
}

int ignorecodecomment(int code[], int start, int len){
    int newstart = start;
    for (int i = start; i < len && code[i] != '\n'; ++i)
        ++newstart;
    if (newstart < len)
        ++newstart; // go over \n
    return newstart;
}

int ignoreblockcomment(int code[], int start, int len){
    int newstart = start + 2;
    for (; newstart < len - 1  && !(code[newstart] == '*' && code[newstart + 1] == '/'); ++newstart)
        ++newstart;
    if (newstart < len)
        ++newstart; // go over \n
    return newstart;
}