#include <string.h>
#include "../s21_math.h"

long double s21_floor(double x) {
    unsigned long input;
    memcpy(&input, &x, 8);
    long exponent = ((input >> 52) & 0x7ff) - 1023;
    if (exponent >= 0) {
        long fractional_bits = 52 - exponent;
        if (fractional_bits > 0) {
            unsigned long integral_mask = 0xffffffffffffffff << fractional_bits;
            unsigned long output = input & integral_mask;
            memcpy(&x, &output, 8);
            if (x < 0 && output != input) x -= 1.0;
        }
    } else {
        x = x < 0 ? -1 : 0;
    }
    return x;
}
