#include "../s21_math.h"
#include <string.h>

long double s21_ceil(double f) {
    int flag = 0;
    unsigned long input;
    memcpy(&input, &f, 8);
    long exponent = ((input >> 52) & 0x7ff) - 1023;
    if (exponent < 0)
        flag = 1;

    long fractional_bits = 52 - exponent;
    if (fractional_bits <= 0)
        flag = 2;

    unsigned long integral_mask = 0xffffffffffffffff << fractional_bits;
    unsigned long output = input & integral_mask;

    if (flag == 0) {
        memcpy(&f, &output, 8);
        if (f > 0 && output != input)
            ++f;
    } else if (flag == 1) {
        f = f > 0;
    }
    return f;
}
