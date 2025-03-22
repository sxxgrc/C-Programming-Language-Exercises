#include <stdio.h>

#define IN_BASE_COMMENT 0
#define IN_STAR_COMMENT 1
#define NOT_IN_COMMENT  2
#define SLASH           0
#define ASTERISK        1
#define NOT_SPECIAL     2

main() {
    int c;
    char last_char = NOT_SPECIAL;
    char state = NOT_IN_COMMENT;
    while ((c = getchar()) != EOF) {
        if (state == IN_BASE_COMMENT) {
            if (c == '\n') {
                state = NOT_IN_COMMENT;
                last_char = NOT_SPECIAL;
                putchar(c);
            }
        } else if (state == IN_STAR_COMMENT) {
            if (c == '/' && last_char == ASTERISK) {
                state = NOT_IN_COMMENT;
                last_char = NOT_SPECIAL;
            } else if (c == '*')
                last_char = ASTERISK;
        } else {
            if (c == '/') {
                if (last_char == SLASH)
                    state = IN_BASE_COMMENT;
                last_char = SLASH;
            } else if (c == '*') {
                if (last_char == SLASH)
                    state = IN_STAR_COMMENT;
                last_char = ASTERISK;
            } else {
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