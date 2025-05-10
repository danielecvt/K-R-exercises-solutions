#include <stdio.h>

main(){
    int c, tab = 0, blank = 0, nl = 0;
    while ((c = getchar()) != EOF){
        if (c == '\t')
            ++tab;
        if (c == ' ' )
            ++blank;
        if (c == '\n')
            ++nl;
    }
    printf("Blank: %d Tabs: %d New lines: %d",blank, tab, nl);

}