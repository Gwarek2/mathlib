#include "s21_math.h"
#include <float.h>
#include <stdio.h>

int main(void) {
    /* double x = DBL_MAX; */
    double x = 0.2133;
    printf("%Lf", s21_cos(x));
    return 0;
}
