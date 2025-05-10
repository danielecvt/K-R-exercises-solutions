#include <stdio.h>

int main(){
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == "\t")
            c = "\\t";
        if (c == "\b")
            c = "\\b";
        if (c == "\\")
            c = "\\\\";
        putchar(c);
    }
    
    return 0;
}