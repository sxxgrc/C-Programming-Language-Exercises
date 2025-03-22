#include <stdio.h>

#define TAB_SIZE 5

main() {
    int c, i, x;
    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            i = 0;
        } else if (c == '\t') {
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
