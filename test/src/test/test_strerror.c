#include "test.h"

START_TEST(strerror1) {
    int error_code = 0;
    ck_assert_str_eq(strerror(error_code), s21_strerror(error_code));
}
END_TEST

START_TEST(strerror2) {
    int error_code = 2;
    ck_assert_str_eq(strerror(error_code), s21_strerror(error_code));
}
END_TEST

START_TEST(strerror3) {
    int error_code = 13;
    ck_assert_str_eq(strerror(error_code), s21_strerror(error_code));
}
END_TEST

START_TEST(strerror4) {
    int error_code = 2147483647;
    ck_assert_str_eq(strerror(error_code), s21_strerror(error_code));
}
END_TEST

// START_TEST(strerror5) {
//     int error_code = -2147483648;
//     ck_assert_str_eq(strerror(error_code), s21_strerror(error_code));
// }
// END_TEST

Suite *suite_strerror(void) {
    Suite *s = suite_create("strerror");
    TCase *tc = tcase_create("strerror_tc");

    tcase_add_test(tc, strerror1);
    tcase_add_test(tc, strerror2);
    tcase_add_test(tc, strerror3);
    tcase_add_test(tc, strerror4);
    //tcase_add_test(tc, strerror5);

    suite_add_tcase(s, tc);
    return s;
}