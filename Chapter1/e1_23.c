#include <stdio.h>

/**
 * Problem Statement:
 * Write a program to remove all comments from a C program. Don't forget to handle quoted strings 
 * and character constants properly. C comments do not nest.
 */

// Define states for where we are in the program.
#define IN_BASE_COMMENT 0
#define IN_STAR_COMMENT 1
#define NOT_IN_COMMENT  2

// Define states for the last character we have seen in the input.
#define SLASH           0
#define ASTERISK        1
#define NOT_SPECIAL     2

main() {
    int c;
    char last_char = NOT_SPECIAL;
    char state = NOT_IN_COMMENT;
    while ((c = getchar()) != EOF) {
        if (state == IN_BASE_COMMENT) {
            // In a comment just like this one. Can only exit when on a new line.
            if (c == '\n') {
                state = NOT_IN_COMMENT;
                last_char = NOT_SPECIAL;
                putchar(c);
            }
        } else if (state == IN_STAR_COMMENT) {
            /* On a comment like this one. Can only exit when properly closed, i.e.: */
            if (c == '/' && last_char == ASTERISK) {
                state = NOT_IN_COMMENT;
                last_char = NOT_SPECIAL;
            } else if (c == '*')
                last_char = ASTERISK;
        } else {
            // Not in a comment. Check to see if we are entering one with new char.
            if (c == '/') {
                if (last_char == SLASH)
                    state = IN_BASE_COMMENT;
                last_char = SLASH;
            } else if (c == '*') {
                if (last_char == SLASH)
                    state = IN_STAR_COMMENT;
                last_char = ASTERISK;
            } else {
                // Impossible to be in a comment, but may have skipped / or * so print those too.
                if (last_char == SLASH)
                    putchar('/');
                else if (last_char == ASTERISK)
                    putchar('*');
                
                putchar(c);
                last_char = NOT_SPECIAL;
            }
        }
    }

    return 0;
}