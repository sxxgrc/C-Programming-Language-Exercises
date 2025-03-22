#include <stdio.h>

#define X   'X'
#define ASCII 128

main() {
    int c, max_count;
    max_count = 0;

    int char_counts[ASCII], i;
    for (i = 0; i < ASCII; i++)
        char_counts[i] = 0;

    while ((c = getchar()) != EOF)
        if (c != '\n' && c != '\t' && c != ' ')
            if ((++char_counts[c]) > max_count)
                max_count = char_counts[c];

    // Output.
    putchar('\n');

    int j;
    for (i = 0; i < max_count; i++) {
        printf("%4d  |", max_count - i);
        for (j = 0; j < ASCII; j++)
            if (char_counts[j] > 0)
                if (max_count - char_counts[j] <= i)
                    putchar(X);
                else
                    putchar(' ');
        putchar('\n');
    }

    for (i = 0; i < (max_count + 13); i++)
        putchar('-');
    putchar('\n');

    printf("       ");
    for (c = 0; c < ASCII; c++)
        if (char_counts[c] > 0)
            putchar(c);
    putchar('\n');
}