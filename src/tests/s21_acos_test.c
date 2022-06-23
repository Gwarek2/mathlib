#include "test_main.h"

START_TEST(test_pos) {
    double x = 0.999;
    ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), TEST_EPS);
} END_TEST

START_TEST(test_pos2) {
    double x = 0.001;
    ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), TEST_EPS);
} END_TEST

START_TEST(test_neg) {
    double x = -0.001;
    ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), TEST_EPS);
} END_TEST

START_TEST(test_neg2) {
    double x = -0.9999;
    ck_assert_ldouble_eq_tol(acos(x), s21_acos(x), TEST_EPS);
} END_TEST

START_TEST(test_nul) {
    double x = 1.001;
    ck_assert_ldouble_nan(s21_acos(x));
} END_TEST

START_TEST(test_nul2) {
    double x = -1.1;
    ck_assert_ldouble_nan(s21_acos(x));
} END_TEST


Suite *suite_s21_acos(void) {
    Suite *s = suite_create("s21_acos");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_pos);
    tcase_add_test(tc, test_pos2);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_neg2);
    tcase_add_test(tc, test_nul);
    tcase_add_test(tc, test_nul2);

    suite_add_tcase(s, tc);
    return s;
}