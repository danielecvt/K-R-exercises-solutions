#include <stdio.h>

int main(){
    int c, nc;
    while((c = getchar()) != EOF){
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');
        else
            putchar('#');
    }
    return 0;
}