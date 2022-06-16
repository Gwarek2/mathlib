#include <math.h>
#include "../s21_math.h"

static const double TWO_PI = 2*S21_PI;
static const double SIN_EPS = 1e-6l;

long double s21_sin(double x) {
// TODO(julireyn): change fabs on s21_fabs
    if (fabs(x) > TWO_PI)
    // TODO(julireyn): change fmod on s21_fmod
        x = fmod(x, TWO_PI);

    int i = 1;
    double numerator = x;
    double divisor = 1;
    double div_result = 1;
    double result = x;

    do {
        divisor *= ((i << 1)*((i << 1) + 1));
        numerator *= -1*x*x;
        div_result = numerator / divisor;
        result += div_result;
        i++;
    // TODO(julireyn): change fabs on s21_fabs
    } while (fabs(div_result) > SIN_EPS);

    return result;
}

