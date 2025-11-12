/**
 * Write an alternate version of squeeze(s1,s2) that deletes each character in the string s1 that matches any character in the string s2 .
 */
#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    char change_flag;
    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        change_flag = 0;

        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                change_flag = 1;
                break;
            }
        }

        if (!change_flag)
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "Hello I'm a fellow programmer";
    char s2[] = "elo";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}
