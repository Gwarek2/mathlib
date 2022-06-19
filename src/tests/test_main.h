#ifndef TEST

#define TEST

#include <math.h>
#include <stdlib.h>
#include <check.h>

#include "../s21_math.h"

#define ARRAY_SIZE(arr) (sizeof((arr)) / sizeof((arr)[0]))

Suite *suite_s21_fabs(void);

#endif  // TEST
