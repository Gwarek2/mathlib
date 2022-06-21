#include "s21_math.h"
#include <math.h>
#include <stdio.h>

int main(void) {
    double x = nan;
    printf("%Lf \n", s21_cos(x));
    printf("%lf ", cos(x));

    return 0;
}
