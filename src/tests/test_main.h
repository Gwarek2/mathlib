#ifndef TEST

#define TEST

#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "../s21_math.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

Suite *suite_s21_abs(void);
Suite *suite_s21_ceil(void);

#endif // TEST
