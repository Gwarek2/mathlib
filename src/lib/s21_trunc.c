#include <string.h>
#include "../s21_math.h"

long double s21_trunc(double x) {
    if (!is_nan(x) && !is_inf(x)) {
        long unsigned input;
        memcpy(&input, &x, 8);
        int exponent = ((input >> 52) & 0x7ff) - 1023;
        if (exponent > 0) {
            int fractional_bits = 52 - exponent;
            if (fractional_bits > 0) {
                long unsigned integral_mask = 0xffffffffffffffff << fractional_bits;
                long unsigned output = input & integral_mask;
                memcpy(&x, &output, 8);
            }
        }
    }
    return x;
}
