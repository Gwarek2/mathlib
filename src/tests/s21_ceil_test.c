#include "test_main.h"

START_TEST(test_zero) { ck_assert_int_eq(ceil(0), s21_ceil(0)); }
END_TEST

START_TEST(test_neg) { ck_assert_int_eq(ceil(-1234), s21_ceil(-1234)); }
END_TEST

START_TEST(test_pos) { ck_assert_int_eq(ceil(1234), s21_ceil(1234)); }
END_TEST

START_TEST(test_normal) { ck_assert_int_eq(ceil(1.7), s21_ceil(1.7)); }
END_TEST

START_TEST(test_normal_negative) {
    ck_assert_int_eq(ceil(-1.7), s21_ceil(-1.7));
}
END_TEST

Suite *suite_s21_ceil(void) {
    Suite *s = suite_create("s21_ceil");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_pos);
    tcase_add_test(tc, test_normal);
    tcase_add_test(tc, test_normal_negative);

    suite_add_tcase(s, tc);
    return s;
}
