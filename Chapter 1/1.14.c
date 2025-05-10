#include <stdio.h>

int main(){
    
    int chars[26], c;

    for (int i = 0; i < 26; ++i)
        chars[i] = 0;

    while ((c = getchar()) != EOF)
        if ('a' <= c <= 'z')
            ++chars[c - 'a'];
    
    for (int i = 0; i < 26; ++i)
        printf("%c%d ", i + 'a', chars[i]);

    return 0;
}