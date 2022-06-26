#include "s21_math.h"

static const double SIN_EPS = 1e-6l;

long double s21_sin(double x) {
    int sign;
    if (x >= 0) {
        sign = 1;
    } else {
        x *= -1;
        sign = -1;
    }
    if (s21_fabs(x) >= SIN_EPS) x = s21_fmod(x, S21_PI);

    int i = 1;
    double numerator = x;
    double divisor = 1;
    double div_result = 1;
    double result = x;

    do {
        divisor *= ((i << 1) * ((i << 1) + 1));
        numerator *= -1 * x * x;
        div_result = numerator / divisor;
        result += div_result;
        i++;
    } while (s21_fabs(div_result) > SIN_EPS);

    return result * sign;
}

