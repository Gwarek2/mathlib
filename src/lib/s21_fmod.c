#include "../s21_math.h"

long double s21_fmod(double x, double y) {
    long double result = S21_NAN;
    if (!is_inf(x) && !is_nan(x) && !is_nan(y) && !is_inf(y) && x != 0 && y != 0) {
        long long int private = x / y;
        long double without_trace = y * private;
        result = x - without_trace;
    } else if (!is_inf(x) && is_inf(y)) {
        result = x;
    }

    return result;
}