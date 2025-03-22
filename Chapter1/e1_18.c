#include <stdio.h>

/**
 * Problem Statement:
 * Write a program to remove all trailing blanks and tabs from each line of input, and to delete 
 * entirely blank lines.
 */

#define MAX_LENGTH 1000

int get_cleaned_line(char a[], int maxlength);

main() {
    char cur_line[MAX_LENGTH];
    int length;

    // Go through all input lines, clean them, copy them, and print them if not empty.
    while ((length = get_cleaned_line(cur_line, MAX_LENGTH)) >= 0)
        if (length > 0)
            printf("%s", cur_line);

    return 0;
}

int get_cleaned_line(char target_string[], int limit) {
    int c, i, last_nonspace_idx;
    last_nonspace_idx = -2;

    // Go through current line, keeping track of the last character that is not a space or tab.
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ) {
        if (c == '\t')
            c = ' ';
        
        if (c != ' ') {
            last_nonspace_idx = i;
            target_string[i++] = c;
        } else if (last_nonspace_idx == i - 1)
            target_string[i++] = c;
    }

    // Place end of string after last character that is not a space or tab.
    if (last_nonspace_idx >= 0) {
        if (c == '\n')
            target_string[++last_nonspace_idx] = c;

        target_string[++last_nonspace_idx] = '\0';
    } else if (i > 0 || c == '\n') // Didn't reach any nonspace characters.
        return 0;

    return last_nonspace_idx;
}
