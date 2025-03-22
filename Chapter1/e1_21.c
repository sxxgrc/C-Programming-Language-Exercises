#include <stdio.h>

#define TAB_STOP 10
#define TAB_SIZE 4

void handle_spaces(int numspaces);

/**
 *  Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. Use the same stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
 */

main() {
    int c, i, x, last_space;
    i = 0;
    last_space = TAB_STOP;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (last_space >= i)
                last_space = i;
            else if (i == TAB_STOP - 1) {
                handle_spaces(i - last_space + 1);
                last_space = TAB_STOP;
            }
        } else {
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

    for (i = 0; i < num_tabs + num_spaces; i++) {
        if (i < num_tabs)
            putchar('\t');
        else
            putchar(' ');
    }
}
