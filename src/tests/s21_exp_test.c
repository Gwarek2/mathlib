#include "test_main.h"

START_TEST(test_pos) {
    double x = 14.67;
    ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), TEST_EPS);
} END_TEST

START_TEST(test_pos_less_than_one) {
    double x = 0.345;
    ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), TEST_EPS);
}

START_TEST(test_neg_less_than_one) {
    double x = -0.767;
    ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), TEST_EPS);
}

START_TEST(test_neg) {
    double x = -13.567;
    ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), TEST_EPS);
} END_TEST

START_TEST(test_zero) {
    double x = 0;
    ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), TEST_EPS);
} END_TEST

START_TEST(test_nan_pos) {
    double x = NAN;
    ck_assert_ldouble_nan(s21_exp(x));
} END_TEST

START_TEST(test_nan_neg) {
    double x = -NAN;
    ck_assert_ldouble_nan(s21_exp(x));
} END_TEST

START_TEST(test_inf_pos) {
    double x = INFINITY;
    ck_assert_ldouble_infinite(s21_exp(x));
} END_TEST

START_TEST(test_inf_neg) {
    double x = -INFINITY;
    ck_assert_ldouble_eq_tol(exp(x), s21_exp(x), TEST_EPS);
} END_TEST

Suite *suite_s21_exp(void) {
    Suite *s = suite_create("s21_exp");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_pos);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_pos_less_than_one);
    tcase_add_test(tc, test_neg_less_than_one);
    tcase_add_test(tc, test_nan_pos);
    tcase_add_test(tc, test_nan_neg);
    tcase_add_test(tc, test_inf_pos);
    tcase_add_test(tc, test_inf_neg);

    suite_add_tcase(s, tc);
    return s;
}
