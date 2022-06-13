#ifndef TEST

#define TEST

#include <math.h>
#include <stdlib.h>
#include <check.h>

#include "../s21_math.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))
#define TEST_EPS 1e-6L

Suite *suite_s21_abs(void);
Suite *suite_s21_exp(void);
Suite *suite_s21_log(void);

#endif  // TEST
