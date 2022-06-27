#include "test_main.h"

START_TEST(test_pos) {
    double x = 534536.34523;
    double y = 2345.34535;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_neg) {
    double x = -5345346.34523;
    double y = 2345.34535;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_neg2) {
    double x = 5345346.34523;
    double y = -2345.34535;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_neg_two) {
    double x = -10.1;
    double y = -3.;
    ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}

START_TEST(test_nul) {
    double x = 5345346.34523;
    double y = 0;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_nul2) {
    double x = 0;
    double y = 4353.64564;
    ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_nul3) {
    double x = 0;
    double y = -S21_NAN;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_nan) {
    double x = S21_NAN;
    double y = 245.34535;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_nan2) {
    double x = 245.34535;
    double y = S21_NAN;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_inf) {
    double x = S21_INF;
    double y = 4323.432543;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_inf2) {
    double x = 436645.34523;
    double y = S21_INF;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_inf3) {
    double x = 436645.34523;
    double y = -S21_INF;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

START_TEST(test_inf4) {
    double x = -S21_INF;
    double y = 0;
    ck_assert_ldouble_nan(s21_fmod(x, y));
} END_TEST

START_TEST(test_inf5) {
    double x = 0;
    double y = S21_INF;
    ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
} END_TEST

Suite *suite_s21_fmod(void) {
    Suite *s = suite_create("s21_fmod");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_pos);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_neg2);
    tcase_add_test(tc, test_neg_two);
    tcase_add_test(tc, test_nul);
    tcase_add_test(tc, test_nul2);
    tcase_add_test(tc, test_nul3);
    tcase_add_test(tc, test_nan);
    tcase_add_test(tc, test_nan2);
    tcase_add_test(tc, test_inf);
    tcase_add_test(tc, test_inf2);
    tcase_add_test(tc, test_inf3);
    tcase_add_test(tc, test_inf4);
    tcase_add_test(tc, test_inf5);
    suite_add_tcase(s, tc);
    return s;
}
