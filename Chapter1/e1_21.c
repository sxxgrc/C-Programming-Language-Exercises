#include <stdio.h>

/**
 * Problem Statement:
 * Write a program entab that replaces strings of blanks with the minimum number of tabs and 
 * blanks to achieve the same spacing.
 */

#define TAB_STOP 10
#define TAB_SIZE 4

void handle_spaces(int numspaces);

main() {
    int c, i, x, last_space;
    i = 0;
    last_space = TAB_STOP;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            // Keep track of the last time we saw a space in input.
            if (last_space >= i)
                last_space = i;
            else if (i == TAB_STOP - 1) {
                // Reached tab stop so handle any spaces so far.
                handle_spaces(i - last_space + 1);
                last_space = TAB_STOP;
            }
        } else {
            // Reached a non-space, so handle all previous spaces if any.
            if (last_space < i) {
                handle_spaces(i - last_space);
                last_space = TAB_STOP;
            }
            if (c == '\n')
                i = 0;

            putchar(c);
        }

        if (++i == TAB_STOP)
            i = 0;
    }

    return 0;
}

void handle_spaces(int numspaces) {
    int num_tabs, num_spaces, i;
    num_tabs = numspaces / TAB_SIZE;
    num_spaces = numspaces % TAB_SIZE;

    // Replace sequence of spaces with the minimum number of tabs and spaces.
    for (i = 0; i < num_tabs + num_spaces; i++) {
        if (i < num_tabs)
            putchar('\t');
        else
            putchar(' ');
    }
}
