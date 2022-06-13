#include "test_main.h"


int main(void) {
    Suite* test_suites[] = {
        suite_s21_abs(),
        suite_s21_exp(),
        suite_s21_log(),
    };

    SRunner *sr = srunner_create(test_suites[0]);
    srunner_set_fork_status(sr, CK_NOFORK);
    int nf;

    for (size_t i = 1; i < ARRAY_SIZE(test_suites); i++)
        srunner_add_suite(sr, test_suites[i]);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
