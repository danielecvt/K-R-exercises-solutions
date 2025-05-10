#include <stdio.h>

int main(){
    
    int c, blank;
    while ((c = getchar()) != EOF){
        if (c == ' ' ){
            //if c in ' ' while blank is '  do nothing,
            // when blank is not ' ' putchar(blank)
            while ((blank = getchar()) == ' ')
                ;
            putchar(blank);
        }
        putchar(c);
    }
    return 0;
}