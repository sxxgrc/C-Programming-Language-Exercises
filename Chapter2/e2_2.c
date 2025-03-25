#include <stdio.h>

/**
 * Problem statement:
 * 
 * Given the for loop: for(i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) s[i] = c
 * Write an equivalent loop without using && or ||.
 */

#define MAX 10

main() {
    char s[MAX];
    int i = 0, c;

    while (i < MAX - 1) {
        if ((c = getchar()) != '\n')
            if (c != EOF)
                s[i] = c;
        i++;
    }    

    return 0;
}