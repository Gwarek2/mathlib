#include <stdio.h>
#include <math.h>


long double s21_sin(x) {

    return x - pow(x, 3) / 3;
}

int main() {
    printf("%Lf", s21_sin(0.4));

    printf("%f", acos(0.22));

    return 0;
}