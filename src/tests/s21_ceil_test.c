#include "test_main.h"

START_TEST(test_zero) { ck_assert_ldouble_eq(ceil(0), s21_ceil(0)); }
END_TEST

START_TEST(test_neg) { ck_assert_ldouble_eq(ceil(-1234), s21_ceil(-1234)); }
END_TEST

START_TEST(test_pos) { ck_assert_ldouble_eq(ceil(1234), s21_ceil(1234)); }
END_TEST

START_TEST(test_pos_1) { ck_assert_ldouble_eq(ceil(1), s21_ceil(1)); }
END_TEST

START_TEST(test_normal) { ck_assert_ldouble_eq(ceil(1.7), s21_ceil(1.7)); }
END_TEST

START_TEST(test_normal_negative) {
    ck_assert_int_eq(ceil(-1.7), s21_ceil(-1.7));
}
END_TEST

START_TEST(test_normal_negative_1) {
    ck_assert_int_eq(floor(-0.7), s21_floor(-0.7));
}
END_TEST

START_TEST(test_normal_above_1) {
    ck_assert_ldouble_eq(ceil(14.7), s21_ceil(14.7));
}
END_TEST
START_TEST(test_lesser_than_1) {
    ck_assert_ldouble_eq(ceil(0.7), s21_ceil(0.7));
}
END_TEST
START_TEST(test_positive_inf) {
    ck_assert_ldouble_eq(ceil(S21_INF), s21_ceil(S21_INF));
}
END_TEST
START_TEST(test_negative_inf) {
    ck_assert_ldouble_eq(ceil(-S21_INF), s21_ceil(-S21_INF));
}
END_TEST

START_TEST(test_nan) { ck_assert_ldouble_nan(s21_ceil(S21_NAN)); }
END_TEST

START_TEST(test_tolerance_pos) {
    double a = 0.1;
    int i = _i;
    ck_assert_ldouble_eq_tol(ceil(a * i), s21_ceil(a * i), TEST_EPS);
}
END_TEST

START_TEST(test_tolerance_neg) {
    double a = 0.1;
    int i = _i;
    ck_assert_ldouble_eq_tol(ceil(-a * i), s21_ceil(-a * i), TEST_EPS);
}
END_TEST

Suite *suite_s21_ceil(void) {
    Suite *s = suite_create("s21_ceil");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_pos);
    tcase_add_test(tc, test_pos_1);
    tcase_add_test(tc, test_normal);
    tcase_add_test(tc, test_normal_negative);
    tcase_add_test(tc, test_normal_negative_1);
    tcase_add_test(tc, test_normal_above_1);
    tcase_add_test(tc, test_negative_inf);
    tcase_add_test(tc, test_lesser_than_1);
    tcase_add_test(tc, test_positive_inf);
    tcase_add_test(tc, test_nan);
    tcase_add_loop_test(tc, test_tolerance_pos, 0, 520);
    tcase_add_loop_test(tc, test_tolerance_neg, 0, 520);
    suite_add_tcase(s, tc);
    return s;
}
