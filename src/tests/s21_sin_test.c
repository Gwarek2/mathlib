#include "test_main.h"

START_TEST(test_sin_small_positive) {
    double x = 2.523;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_small_negative) {
    double x = -2.523;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_huge_positive) {
    double x = 400000.23;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_huge_negative) {
    double x = -400000.23;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_zero) {
    double x = 0;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

START_TEST(test_sin_nan) {
    double x = NAN;
    ck_assert_ldouble_nan(s21_sin(x));
} END_TEST

START_TEST(test_sin_inf) {
    double x = INFINITY;
    ck_assert_ldouble_nan(s21_sin(x));
} END_TEST

START_TEST(test_sin_fractional_pi_values) {
    for (int i = -10; i <= 10 && i != 0; i++) {
       ck_assert_ldouble_eq_tol(sin(S21_PI / i), s21_sin(S21_PI / i), TEST_EPS);
    }
} END_TEST

START_TEST(test_sin_whole_pi_values) {
    for (int i = -10; i <= 10; i++) {
        ck_assert_ldouble_eq_tol(sin(S21_PI * i), s21_sin(S21_PI * i), TEST_EPS);
    }
} END_TEST

START_TEST(test_sin_big_mantissa) {
    double x = 0.12345678901234567890;
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), TEST_EPS);
} END_TEST

Suite *suite_s21_sin(void) {
    Suite *s = suite_create("s21_sin");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_sin_small_positive);
    tcase_add_test(tc, test_sin_small_negative);
    tcase_add_test(tc, test_sin_huge_positive);
    tcase_add_test(tc, test_sin_huge_negative);
    tcase_add_test(tc, test_sin_zero);
    tcase_add_test(tc, test_sin_nan);
    tcase_add_test(tc, test_sin_inf);
    tcase_add_test(tc, test_sin_fractional_pi_values);
    tcase_add_test(tc, test_sin_whole_pi_values);
    tcase_add_test(tc, test_sin_big_mantissa);

    suite_add_tcase(s, tc);
    return s;
}
