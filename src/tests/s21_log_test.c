#include "test_main.h"

START_TEST(test_pos) {
    double x = 2.523;
    ck_assert_ldouble_eq_tol(log(x), s21_log(x), TEST_EPS);
}

START_TEST(test_max) {
    double x = DBL_MAX;
    ck_assert_ldouble_eq_tol(log(x), s21_log(x), TEST_EPS);
}

START_TEST(test_min) {
    double x = DBL_MIN;
    ck_assert_ldouble_eq_tol(log(x), s21_log(x), TEST_EPS);
}

START_TEST(test_pos_1) {
    double x = 4.3234323e-43;
    ck_assert_ldouble_eq_tol(log(x), s21_log(x), TEST_EPS);
}

START_TEST(test_neg) {
    double x = -3432.12;
    ck_assert_ldouble_nan(s21_log(x));
}

START_TEST(test_zero) {
    double x = 0;
    ck_assert_ldouble_infinite(s21_log(x));
}

START_TEST(test_nan_pos) {
    double x = NAN;
    ck_assert_ldouble_nan(s21_log(x));
}

START_TEST(test_nan_neg) {
    double x = -NAN;
    ck_assert_ldouble_nan(s21_log(x));
}

START_TEST(test_inf_pos) {
    double x = INFINITY;
    ck_assert_ldouble_infinite(s21_log(x));
}

START_TEST(test_inf_neg) {
    double x = -INFINITY;
    ck_assert_ldouble_nan(s21_log(x));
}

Suite *suite_s21_log(void) {
   Suite *s = suite_create("s21_log");
   TCase *tc = tcase_create("core");

   tcase_add_test(tc, test_pos);
   tcase_add_test(tc, test_pos_1);
   tcase_add_test(tc, test_max);
   tcase_add_test(tc, test_min);
   tcase_add_test(tc, test_neg);
   tcase_add_test(tc, test_zero);
   tcase_add_test(tc, test_nan_pos);
   tcase_add_test(tc, test_nan_neg);
   tcase_add_test(tc, test_inf_pos);
   tcase_add_test(tc, test_inf_neg);

   suite_add_tcase(s, tc);
   return s;
}
