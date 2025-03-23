#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

/**
 * Problem Statement:
 * Write a program to determine the ranges of char, short, int, and long variables, both signed 
 * and unsigned, by printing appropriate values from standard headers and by direct computation. 
 * Harder if you compute them: determine the ranges of the various floating-point types.
 */

main() {
    printf("----- Defined Limits from Headers -----\n");
    
    printf("\nChars:\n");
    printf("Unsigned char min: 0, unsigned char max: %d\n", UCHAR_MAX);
    printf("Char min: %d, char max: %d\n", CHAR_MIN, CHAR_MAX);

    printf("\nShorts:\n");
    printf("Unsigned short min: 0, unsigned short max: %d\n", USHRT_MAX);
    printf("Short min: %d, short max: %d\n", SHRT_MIN, SHRT_MAX);

    printf("\nInts:\n");
    printf("Unsigned int min: 0, unsigned int max: %u\n", UINT_MAX);
    printf("Int min: %d, int max: %d\n", INT_MIN, INT_MAX);

    printf("\nLongs:\n");
    printf("Unsigned long min: 0, unsigned long max: %lu\n", ULONG_MAX);
    printf("Long min: %ld, long max: %ld\n", LONG_MIN, LONG_MAX);

    printf("\nFloats:\n");
    printf("Float min: %.10e, float max: %.10e\n", FLT_MIN, FLT_MAX);
    
    printf("\nDoubles:\n");
    printf("Double min: %.10e, double max: %.10e\n", DBL_MIN, DBL_MAX);

    printf("\n\n----- Computed Limits -----\n");
    
    printf("\nChars:\n");
    
    unsigned char uc_max = 0;
    uc_max--;
    printf("Unsigned char min: 0, unsigned char max: %d\n", uc_max);

    char c_max = uc_max / 2;
    char c_min = (c_max * -1) - 1;
    printf("Char min: %d, char max: %d\n", c_min, c_max);

    printf("\nShorts:\n");

    unsigned short us_max = 0;
    us_max--;
    printf("Unsigned short min: 0, unsigned short max: %d\n", us_max);
     
    short s_max = us_max / 2;
    short s_min = (s_max * -1) - 1;
    printf("Short min: %d, short max: %d\n", s_min, s_max);
    

    printf("\nInts:\n");

    unsigned int ui_max = 0;
    ui_max--;
    printf("Unsigned int min: 0, unsigned int max: %u\n", ui_max);
    
    int i_max = ui_max / 2;
    int i_min = (i_max * -1) - 1;
    printf("Int min: %d, int max: %d\n", i_min, i_max);

    printf("\nLongs:\n");

    unsigned long ul_max = 0;
    ul_max--;
    printf("Unsigned long min: 0, unsigned long max: %lu\n", ul_max);
    
    long l_max = ul_max / 2;
    long l_min = (l_max * -1) - 1;
    printf("Long min: %ld, long max: %ld\n", l_min, l_max);

    printf("\nFloats:\n");

    float f_min = pow(2.0, -126);
    float f_max = 1.0;
    for (int i = 1; i <= 23; i++)
        f_max += pow(2, -i);

    f_max *= pow(2, 127);

    printf("Float min: %.10e, float max: %.10e\n", f_min, f_max);
    
    printf("\nDoubles:\n");

    double d_min = pow(2.0, -1022);
    double d_max = 1.0;
    for (int i = 1; i <= 52; i++)
        d_max += pow(2, -i);
    d_max *= pow(2, 1023);

    printf("Double min: %.10e, double max: %.10e\n", d_min, d_max);

    return 0;
}
