#include "../s21_math.h"
long double _factorial(double num);
long double s21_cos(double num) {
    long double result = 0;
    if (!(is_inf(num) || is_nan(num))) {
        for (int i = 0; i < 100; i++) {
            result += s21_pow(-1, i) * s21_pow(num, 2 * i) / _factorial(2 * i);
        }
    } else {
        return S21_NAN;
    }
    return result;
}

long double _factorial(double num) {
    long double result;
    if (num < 0)
        result = 0;
    if (num == 0)
        result = 1;
    else
        result = num * _factorial(num - 1);

    return result;
}
