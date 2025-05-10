#include <stdio.h>
#define MAXLINE 4
/* maximum input line length */
int fgetline(char line[], int maxline);
void copy(char to[], char from[]);
/* print the longest input line */
int main(){

    int len, c = 0;
    /* current line length */
    int max;
    /* maximum length seen so far */
    char line[MAXLINE];
    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while (((len = fgetline(line, MAXLINE)) > 0)){
        /*if is insert a line long MAXLINE and it isn't finished 
        continue to insert char and count the lenght, unfournatelly 
        it can't save the inteir line
        */
        if (len == MAXLINE - 1 && line[MAXLINE] != '\0')
            while ((c = getchar()) != '\n')
                ++len; 
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("%s and its lenght is %d", longest, max);
    return 0;
}
/* getline: read a line into s, return length
 */
int fgetline(char s[], int lim){
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}