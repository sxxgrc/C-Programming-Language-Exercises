#include <stdio.h>

/**
 * Problem Statement:
 * Write a program to "fold" long input lines into two or more shorter lines after the last 
 * non-blank character that occurs before the n-th column of input. Make sure your program does 
 * something intelligent with very long lines, and if there are no blanks or tabs before the 
 * specified column.
 */

#define MAX_COL 10

main() {
    int c, d, i, last_nonspace = -1;
    char line[MAX_COL + 2];
    for (i = 0; (c = getchar()) != EOF; i++) {
        if (i == MAX_COL || c == '\n') {
            // Reached end of line or max size. If not empty, remove all spaces and print.
            if (last_nonspace < 0)
                i = 0;
            else {
                line[last_nonspace + 1] = '\n';
                line[last_nonspace + 2] = '\0';

                // Handle splitting line in middle of a string by adding a hyphen at end.
                if (c != '\n' && c != ' ' && last_nonspace == i - 1) {
                    d = line[last_nonspace];
                    line[last_nonspace] = '-';
                    printf("%s", line);
                    line[0] = d;
                    i = 1;
                    last_nonspace = 0;    
                } else {                
                    printf("%s", line);
                    i = 0;
                    last_nonspace = -1;
                }
            }
        }

        if (c != ' ' && c != '\t')
            last_nonspace = i;

        line[i] = c;
    }

    return 0;
}
