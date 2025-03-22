#include <stdio.h>

#define TARGET_LENGTH 80
#define MAX_LENGTH 1000 

int get_line(char a[], int maxlength);

main() {
    int length;
    char cur_line[MAX_LENGTH];
    while ((length = get_line(cur_line, MAX_LENGTH)) > 0)
        if (length > TARGET_LENGTH)
            printf("<<TARGET LINE FOUND>>: %s", cur_line);

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
