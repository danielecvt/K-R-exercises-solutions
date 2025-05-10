#include <stdio.h>

#define MAXCODECHARS 1000000
#define MAXLINESCODE 1000

int f_get_code(int code[]);
int check_code(int code[], int len);
int ignore_line_comment(int code[], int start, int len);
int ignore_block_comment(int code[], int start, int len);
int ignore_char_or_string(int code[], int start, int len, int c);

int main(){
    int code[MAXCODECHARS], len;
    len = f_get_code(code);
    check_code(code, len);
    return 0;
}

int _totLines = 0;
int f_get_code (int code[]){
    int c, len = 0;
    printf("Insert the code, I'll check it: \n");
    for(int i = 0;((c = getchar()) != EOF) && i < MAXCODECHARS - 1; ++i){
        code[i] = c;
        ++len;
        if (c == '\n')
            ++_totLines;
    }

    if (c != EOF)
        code[++len] = '\n';
    
    putchar('\n'); //new line after inserted code
    return len;
}

int _nLine; // number of line in checking

int check_code(int code[], int len) {
    _nLine = 0;
    int stackPar[MAXLINESCODE], stackBrackets[MAXLINESCODE], stackBraces[MAXLINESCODE];
    int topPar = -1, topBrackets = -1, topBraces = -1;

    for (int i = 0; i < len; ++i) {
        if (i < len -1 && code[i] == '/' && code[i + 1] == '/')
            i = ignore_line_comment(code, i, len);
        else if (i < len -1 && code[i] == '/' && code[i + 1] == '*')
            i = ignore_block_comment(code, i, len);
        else if(code[i] == '\'')
            i = ignore_char_or_string(code, i, len, '\'');
        else if(code[i] == '"')
            i = ignore_char_or_string(code, i, len, '"');
        else if (code[i] == '(')
            stackPar[++topPar] = _nLine;
        else if (code[i] == ')') {
            if (topPar >= 0)
                --topPar;
            else
                printf("Unopened parenthesis in line: %d\n", _nLine + 1);
        }
        else if (code[i] == '[')
            stackBrackets[++topBrackets] = _nLine;
        else if (code[i] == ']'){
            if (topBrackets >= 0)
                --topBrackets;
            else
                printf("Unopened bracket in line: %d\n", _nLine + 1);
        }
        else if (code[i] == '{')
            stackBraces[++topBraces] = _nLine;
        else if (code[i] == '}'){
            if (topBraces >= 0)
                --topBraces;
            else
                printf("Unopened brace in line: %d\n", _nLine + 1);
        }

        if (code[i] == '\n')
            ++_nLine;
    }

    if (topPar == -1 && topBrackets == -1 && topBraces == -1 ){
        printf("Every parenthesis, brackets and braces is ok\n");
        return 0;
    }

    while (topPar >= 0)
        printf("Unclosed parenthesis at line: %d\n", stackPar[topPar--] + 1);
    
    while (topBrackets >= 0) 
        printf("Unclosed brackets at line: %d\n", stackBrackets[topBrackets--] + 1);
    
    while (topBraces >= 0) 
        printf("Unclosed brace at line: %d\n", stackBraces[topBraces--] + 1);
    
        return 0;
}


int ignore_line_comment(int code[], int start, int len){
    int newstart = start;
    for (int i = start; i < len && code[i] != '\n'; ++i)
        ++newstart;
    if (newstart < len) {// go over \n
        ++_nLine;
        ++newstart; 
    }
    return newstart;
}

int ignore_block_comment(int code[], int start, int len){
    int newstart = start + 2;
    for (; newstart < len - 1  && !(code[newstart] == '*' && 
        code[newstart + 1] == '/'); ++newstart)
        if (code[newstart] == '\n')
            ++_nLine;
    
    if (newstart < len)
        ++newstart; // go over \n
    return newstart;
}

int ignore_char_or_string(int code[], int start, int len, int c){
    int startLine = _nLine, newStart = start + 1;
    for (int i = start + 1; i < len; ++i){
        if(code[i] == '\\' && i < len - 1 && code[i + 1] == ' ')
            printf("Not an escape at line: %d\n", _nLine + 1);
        else if (code[i] == '\\' && i < len - 1 && code[i + 1] != ' ') 
            ++i;
        else if (code[i] == '\n')
            ++_nLine;
        else if (code[i] == c)
            return i;
    }
    if (c == '\'')
        printf("Unclosed quote at line: %d\n", startLine + 1);
    else 
        printf("Unclosed double quote at line: %d\n", startLine + 1);

    return len - 1;
} 