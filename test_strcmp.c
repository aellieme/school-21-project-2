#include "test.h"


START_TEST(strncmp1) {
    const char *str1 = "applepie";
    const char *str2 = "apricot"; 
    size_t n = 4;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp2) {
    const char *str1 = "apple\0pie";
    const char *str2 = "apple\0fruit"; 
    size_t n = 6;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp3) {
    const char *str1 = "apple";
    const char *str2 = "apple"; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp4) {
    const char *str1 = "apple";
    const char *str2 = "apples"; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp5) {
    const char *str1 = "apple";
    const char *str2 = "apple"; 
    size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp6) {
    const char *str1 = "apple";
    const char *str2 = "banana"; 
    size_t n = 3;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp7) {
    const char *str1 = "apple";
    const char *str2 = "apricot"; 
    size_t n = 0;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp8) {
    const char *str1 = "apple\0pie";
    const char *str2 = "apple\0fruit"; 
    size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp9) {
    const char *str1 = "";
    const char *str2 = ""; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp10) {
    const char *str1 = "apple";
    const char *str2 = "APPLE"; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp11) {
    const char *str1 = "apple\0pie";
    const char *str2 = "apple\0pie"; 
    size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, strncmp1);
    tcase_add_test(tc1_1, strncmp2);
    tcase_add_test(tc1_1, strncmp3);
    tcase_add_test(tc1_1, strncmp4);
    tcase_add_test(tc1_1, strncmp5);
    tcase_add_test(tc1_1, strncmp6);
    tcase_add_test(tc1_1, strncmp7);
    tcase_add_test(tc1_1, strncmp8);
    tcase_add_test(tc1_1, strncmp9);
    tcase_add_test(tc1_1, strncmp10);
    tcase_add_test(tc1_1, strncmp11);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}