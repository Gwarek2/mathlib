#include "test_main.h"

START_TEST(test_zero) { ck_assert_ldouble_eq(fmod(0, 0), s21_fmod(0, 0)); }
END_TEST
START_TEST(test_pos) { ck_assert_ldouble_eq(fmod(213.433, 1.334), s21_fmod(213.433, 1.334)); }
END_TEST
START_TEST(test_neg) { ck_assert_ldouble_eq(fmod(-5433.43234, 432.543), s21_fmod(-5433.43234, 432.543)); }
END_TEST
START_TEST(test_nan) { ck_assert_ldouble_eq(fmod(-5433.43234, S21_NAN), s21_fmod(-5433.43234, S21_NAN)); }
END_TEST
START_TEST(test_nan2) { ck_assert_ldouble_eq(fmod(S21_NAN, 2.3), s21_fmod(S21_NAN, 2.3)); }
END_TEST
START_TEST(test_fin) { ck_assert_ldouble_eq(fmod(S21_INF, 2.3), s21_fmod(S21_INF, 2.3)); }
END_TEST
START_TEST(test_fin2) { ck_assert_ldouble_eq(fmod(34234.432, S21_INF), s21_fmod(34234.432, S21_INF)); }
END_TEST



Suite *suite_s21_fmod(void) {
    Suite *s = suite_create("s21_abs");
    TCase *tc = tcase_create("core");

    tcase_add_test(tc, test_zero);
    tcase_add_test(tc, test_neg);
    tcase_add_test(tc, test_pos);
    tcase_add_test(tc, test_nan);
    tcase_add_test(tc, test_nan2);
    tcase_add_test(tc, test_fin);
    tcase_add_test(tc, test_fin2);

    suite_add_tcase(s, tc);
    return s;
}