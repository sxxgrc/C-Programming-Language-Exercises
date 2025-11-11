/**
 * Write the function htoi(s) , which converts a string of hexadecimal digits (including an 
 * optional 0x or 0X) into its equivalent integer value. The allowable digits are 0 through 9, a 
 * through f, and A through F .
 */
#include <stdio.h>
#include <string.h>

int htoi(char s[]) {
    int pow = 1, val = 0;
    for (int i = strlen(s) - 1; i >= 0; --i) {
        if (s[i] >= '0' && s[i] <= '9')
            val += (s[i] - '0') * pow;
        else if (s[i] >= 'A' && s[i] <= 'F')
            val += (10 + (s[i] - 'A')) * pow;
        else if (s[i] >= 'a' && s[i] <= 'f')
            val += (10 + (s[i] - 'a')) * pow;

        pow *= 16;
    }

    return val;
}

int main() {
    printf("%d\n", htoi("0Xf3"));
    return 0;
}
