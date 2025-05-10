#include <stdio.h>

int main (){
    int c;
    c = getchar() != EOF; //ctr+d is EOF
    putchar('0' + c);
}