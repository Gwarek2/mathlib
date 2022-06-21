#include "test_main.h"
static const double cos_EPS = 1e-16l;

START_TEST(test_cos_positive) {
    double x = 0.4;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_negative) {
    double x = -0.4;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_zero) {
    double x = 0;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_one) {
    double x = 1;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_one_negative) {
    double x = -1;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_huge_positive) {
    double x = 598987986;
    ck_assert_ldouble_nan(s21_cos(x));
}
END_TEST

START_TEST(test_cos_huge_negative) {
    double x = -5938409234;
    ck_assert_ldouble_nan(s21_cos(x));
}
END_TEST

START_TEST(test_cos_big_mantissa) {
    double x = 0.123456789012345678901234567890;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_eps_positive) {
    double x = 1 + cos_EPS;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST

START_TEST(test_cos_eps_negative) {
    double x = -1 - cos_EPS;
    ck_assert_ldouble_eq_tol(cos(x), s21_cos(x), TEST_EPS);
}
END_TEST
START_TEST(test_cos_inf) { ck_assert_ldouble_nan(s21_cos(INFINITY)); }
END_TEST
START_TEST(test_cos_nan) { ck_assert_ldouble_nan(s21_cos(NAN)); }
END_TEST
START_TEST(test_cos_minus_inf) { ck_assert_ldouble_nan(s21_cos(-INFINITY)); }
END_TEST
Suite *suite_s21_cos(void) {
    Suite *s = suite_create("s21_cos");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_cos_positive);
    tcase_add_test(tc, test_cos_negative);
    tcase_add_test(tc, test_cos_zero);
    tcase_add_test(tc, test_cos_one);
    tcase_add_test(tc, test_cos_negative);
    tcase_add_test(tc, test_cos_one_negative);
    tcase_add_test(tc, test_cos_huge_positive);
    tcase_add_test(tc, test_cos_huge_negative);
    tcase_add_test(tc, test_cos_big_mantissa);
    tcase_add_test(tc, test_cos_eps_positive);
    tcase_add_test(tc, test_cos_eps_negative);
    tcase_add_test(tc, test_cos_inf);
    tcase_add_test(tc, test_cos_nan);
    tcase_add_test(tc, test_cos_minus_inf);
    suite_add_tcase(s, tc);
    return s;
}
