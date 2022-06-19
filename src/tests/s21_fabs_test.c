#include "test_main.h"

START_TEST(test_zero) {
    ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
} END_TEST

START_TEST(test_neg) {
    ck_assert_int_eq(fabs(-3425743948574326.345345), s21_fabs(-3425743948574326.345345));
} END_TEST

START_TEST(test_pos) {
    ck_assert_int_eq(fabs(3425743948574326.345345), s21_fabs(3425743948574326.345345));
} END_TEST


Suite *suite_s21_fabs(void) {
    Suite *s = suite_create("s21_fabs");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_pos);

    suite_add_tcase(s, tc);
    return s;
}
