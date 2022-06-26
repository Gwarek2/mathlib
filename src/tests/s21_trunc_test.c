#include "test_main.h"

START_TEST(test_pos_real) {
    double x = 3.0 / 2.0;
    ck_assert_ldouble_eq_tol(trunc(x), s21_trunc(x), TEST_EPS);
} END_TEST

START_TEST(test_neg_real) {
    double x = -545.1343;
    ck_assert_ldouble_eq_tol(trunc(x), s21_trunc(x), TEST_EPS);
} END_TEST

START_TEST(test_pos_int) {
    double x = 123423.0;
    ck_assert_ldouble_eq_tol(trunc(x), s21_trunc(x), TEST_EPS);
} END_TEST

START_TEST(test_neg_int) {
    double x = -1234.0;
    ck_assert_ldouble_eq_tol(trunc(x), s21_trunc(x), TEST_EPS);
} END_TEST

START_TEST(test_pos_fract) {
    double x = 3.645e-20;
    ck_assert_ldouble_eq_tol(trunc(x), s21_trunc(x), TEST_EPS);
} END_TEST

START_TEST(test_neg_fract) {
    double x = -6.19573e-1;
    ck_assert_ldouble_eq_tol(trunc(x), s21_trunc(x), TEST_EPS);
} END_TEST

START_TEST(test_zero) {
    double x = 0;
    ck_assert_ldouble_eq_tol(trunc(x), s21_trunc(x), TEST_EPS);
} END_TEST

START_TEST(test_nan) {
    double x = NAN;
    ck_assert_ldouble_nan(s21_trunc(x));
} END_TEST

START_TEST(test_pos_inf) {
    double x = INFINITY;
    ck_assert_ldouble_infinite(s21_trunc(x));
} END_TEST

START_TEST(test_neg_inf) {
    double x = INFINITY;
    ck_assert_ldouble_infinite(s21_trunc(x));
} END_TEST

Suite *suite_s21_trunc(void) {
    Suite *s = suite_create("s21_trunc");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_pos_real);
    tcase_add_test(tc, test_neg_real);
    tcase_add_test(tc, test_pos_int);
    tcase_add_test(tc, test_neg_int);
    tcase_add_test(tc, test_pos_fract);
    tcase_add_test(tc, test_neg_fract);
    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_nan);
    tcase_add_test(tc, test_pos_inf);
    tcase_add_test(tc, test_neg_inf);

    suite_add_tcase(s, tc);
    return s;
}
