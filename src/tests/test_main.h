#ifndef TEST

#define TEST

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <float.h>

#include "../s21_math.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))
#define TEST_EPS 1e-6l
#define S21_PI 3.141592653589793

Suite *suite_s21_abs(void);
Suite *suite_s21_exp(void);
Suite *suite_s21_log(void);
Suite *suite_s21_pow(void);
Suite *suite_s21_sin(void);

#endif  // TEST
