#ifndef TEST

#define TEST

#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_math.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))
#define TEST_EPS 1e-6l

Suite *suite_s21_abs(void);
Suite *suite_s21_ceil(void);
Suite *suite_s21_floor(void);
Suite *suite_s21_exp(void);
Suite *suite_s21_log(void);
Suite *suite_s21_pow(void);
Suite *suite_s21_sqrt(void);
Suite *suite_s21_asin(void);
Suite *suite_s21_fabs(void);
Suite *suite_s21_trunc(void);
Suite *suite_s21_sin(void);
Suite *suite_s21_fmod(void);
Suite *suite_s21_acos(void);


#endif  // TEST
