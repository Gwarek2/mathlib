/**
 * Implementation of sqrt function from math library.
**/
#include "../s21_math.h"
#include <math.h>

static const long double SQRT_EPS = 1e-10l;

long double s21_sqrt(double x) {
    long double res = 1;
    if (x < 0) {
        res = -S21_NAN;
    } else if (is_nan(x)) {
        res = S21_NAN;
    } else if (is_inf(x) || x <= SQRT_EPS) {
        res = x;
    } else {
        long double num = x;
        res = s21_exp(s21_log(num) / 2);
    }
    return res;
}
