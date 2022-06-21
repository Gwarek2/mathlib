/**
 * Implementation of exp function from math lib.
 * Uses Tailor series for calculation and aproximation of result
 **/

#include "../s21_math.h"
#include <math.h>

static const long double EXP_EPS = 1e-100;

long double s21_exp(double x) {
    long double res = 1;
    if (is_nan(x)) {
        res = x < 0 ? -S21_NAN : S21_NAN;
    } else if (is_inf(x)) {
        res = x < 0 ? 0 : S21_INF;
    } else {
        long double num = x;
        long double exponent = num;
        long double fact = 1;
        long double part = 1;
        long double i = 2;
        while (fabsl(part) > EXP_EPS) {
            part = exponent / fact;
            res += part;
            exponent *= num;
            fact *= i++;
        }
    }
    return res;
}
