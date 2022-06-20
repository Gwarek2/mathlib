#include "test_main.h"

START_TEST(test_pos_int_1) {
    double x = 64.;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
} END_TEST

START_TEST(test_pos_int_2) {
    double x = 123456789;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
} END_TEST

START_TEST(test_int_min) {
    double x = DBL_MIN;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
}

START_TEST(test_pos_real_1) {
    double x = 2.25;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
} END_TEST

START_TEST(test_pos_real_2) {
    double x = 981.123e+10;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
} END_TEST

START_TEST(test_pos_real_3) {
    double x = 4.163435e-34;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
} END_TEST

START_TEST(test_zero) {
    double x = 0.;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
} END_TEST

START_TEST(test_neg_zero) {
    double x = -0.;
    ck_assert_ldouble_eq_tol(sqrt(x), s21_sqrt(x), TEST_EPS);
} END_TEST

START_TEST(test_neg_int) {
    double x = -121.;
    ck_assert_ldouble_nan(s21_sqrt(x));
} END_TEST

START_TEST(test_neg_real) {
    double x = -2.89;
    ck_assert_ldouble_nan(s21_sqrt(x));
} END_TEST

START_TEST(test_nan) {
    double x = NAN;
    ck_assert_ldouble_nan(s21_sqrt(x));
} END_TEST

START_TEST(test_pos_inf) {
    double x = INFINITY;
    ck_assert_ldouble_infinite(s21_sqrt(x));
} END_TEST

START_TEST(test_neg_inf) {
    double x = -INFINITY;
    ck_assert_ldouble_nan(s21_sqrt(x));
} END_TEST

Suite *suite_s21_sqrt(void) {
    Suite *s = suite_create("s21_sqrt");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_pos_int_1);
    tcase_add_test(tc, test_pos_int_2);
    tcase_add_test(tc, test_int_min);
    tcase_add_test(tc, test_pos_real_1);
    tcase_add_test(tc, test_pos_real_2);
    tcase_add_test(tc, test_pos_real_3);
    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_neg_zero);
    tcase_add_test(tc, test_neg_int);
    tcase_add_test(tc, test_neg_real);
    tcase_add_test(tc, test_nan);
    tcase_add_test(tc, test_pos_inf);
    tcase_add_test(tc, test_neg_inf);

    suite_add_tcase(s, tc);
    return s;
}
