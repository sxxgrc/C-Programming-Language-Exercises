#include <stdio.h>

#define MAXLINE 22

int get_line(char s[], int maxline);
void copy(char s[], char t[]);

main() {
    char cur_line[MAXLINE];
    char biggest[MAXLINE];
    int length, cur_max;
    cur_max = 0;

    while ((length = get_line(cur_line, MAXLINE)) > 0)
        if (length > cur_max) {
            cur_max = length;
            copy(biggest, cur_line);
        }

    printf("%s | Size: %d\n", biggest, cur_max);
    return 0;
}

int get_line(char dest_array[], int limit) {
    int c, i;

    for (i = 0; ((c = getchar()) != EOF) && c != '\n'; i++)
        if (i < limit - 1)
            dest_array[i] = c;
   
    if (i < limit)
        dest_array[i] = '\0';
    else
        dest_array[limit - 1] = '\0';
    return i;
}

void copy(char dest_array[], char source_array[]) {
    int i = 0;
    while ((dest_array[i] = source_array[i]) != '\0')
        i++;
}