#include <stdio.h>

#define MAX_LENGTH 1000

int get_line(char a[], int maxlength);
void reverse(char a[], int length);

main() {
    int length;
    char cur_line[MAX_LENGTH];
    while ((length = get_line(cur_line, MAX_LENGTH)) > 0) {
        if (length > 1)
            reverse(cur_line, length);
        printf("%s", cur_line);
    }

    return 0;
}

int get_line(char dest_string[], int limit) {
    int c, i;
    for (i = 0; (i < limit - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
        dest_string[i] = c;
    
    if (c == '\n')
        dest_string[i++] = c;
    
    dest_string[i] = '\0';

    return i;
}

void reverse(char line[], int length) {
    char c;
    int i, j;
    if (line[length - 1] == '\n')
        length--;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = line[i];
        line[i] = line[j];
        line[j] = c;
    }
}
