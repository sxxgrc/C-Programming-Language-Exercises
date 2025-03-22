#include <stdio.h>

#define MAX_LENGTH 1000

int get_cleaned_line(char a[], int maxlength);

main() {
    char cur_line[MAX_LENGTH];
    int length;
    while ((length = get_cleaned_line(cur_line, MAX_LENGTH)) >= 0)
        if (length > 0)
            printf("%s", cur_line);

    return 0;
}

int get_cleaned_line(char target_string[], int limit) {
    int c, i, last_nonspace_idx;
    last_nonspace_idx = -2;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ) {
        if (c == '\t')
            c = ' ';
        
        if (c != ' ') {
            last_nonspace_idx = i;
            target_string[i++] = c;
        } else if (last_nonspace_idx == i - 1)
            target_string[i++] = c;
    }

    if (last_nonspace_idx >= 0) {
        if (c == '\n')
            target_string[++last_nonspace_idx] = c;

        target_string[++last_nonspace_idx] = '\0';
    } else if (i > 0 || c == '\n')
        return 0;

    return last_nonspace_idx;
}
