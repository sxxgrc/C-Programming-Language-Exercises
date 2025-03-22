#include <stdio.h>

/**
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space 
 * to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a 
 * variable or a symbolic parameter?
 */

#define TAB_SIZE 5

main() {
    int c, i, x;
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            i = 0;
        } else if (c == '\t') {
            // Replace tab with spaces up to next tab stop.
            x = TAB_SIZE - (i % TAB_SIZE);
            while (x-- > 0)
                putchar(' ');
        } else {
            putchar(c);
            i++;
        }
    }

    return 0;
}
