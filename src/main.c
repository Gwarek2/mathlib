#include "s21_math.h"
#include <stdio.h>
#include <string.h>
int main(void) {
    float x = -4.1;
    printf("%Lf\n", s21_ceil(x));

    printf("%Lf\n", s21_floor(x));

    return 0;
}
