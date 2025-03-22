#include <stdio.h>

/**
 * Problem Statement:
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#define IN  1
#define OUT 0
#define X   'X'
#define MAX 10

main() {
    int c, cur_length, state, max_count;
    cur_length = max_count = 0;
    state = OUT;

    int lengths[MAX + 1], i;
    for (i = 0; i < MAX + 1; i++)
        lengths[i] = 0;

    // Go through all of input and collect sizes/counts of all words.
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN) {
                if (cur_length > MAX)
                    cur_length = MAX + 1;
                
                lengths[cur_length - 1]++;

                if (lengths[cur_length - 1] > max_count)
                    max_count = lengths[cur_length - 1];

                cur_length = 0;
            }
            state = OUT;
        } else {
            state = IN;
            cur_length++;
        }
    }
    putchar('\n');

    // Print the histogram out vertically (minus bottom labels).
    int j;
    for (i = 0; i < max_count; i++) {
        printf("%4d  |", max_count - i);
        for (j = 0; j < MAX + 1; j++)
            if (max_count - lengths[j] <= i)
                printf(" X ");
            else
                printf("   ");
        putchar('\n');
    }

    // Print bottom border.
    for (i = 0; i < (7 + (3 * MAX + 1) + 9); i++)
        putchar('-');
    putchar('\n');

    // Print bottom labels for counts.
    printf("       ");
    for (i = 1; i <= MAX; i++)
        printf(" %d ", i);
    printf(" >%d ", MAX);
    putchar('\n');
}