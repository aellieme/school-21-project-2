#include "test.h"


START_TEST(strncmp1) {
    const char *str1 = "applepie";
    const char *str2 = "apricot"; 
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp2) {
    const char *str1 = "applepie";
    const char *str2 = "apricot"; 
    s21_size_t n = 4;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp3) {
    const char *str1 = "apple\0pie";
    const char *str2 = "apri\0cot"; 
    s21_size_t n = 8;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp4) {
    const char *str1 = "\0applepie";
    const char *str2 = "\0apricot"; 
    s21_size_t n = 9;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp5) {
    const char *str1 = "";
    const char *str2 = ""; 
    s21_size_t n = 1;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp6) {
    const char *str1 = "apple";
    const char *str2 = "apricot"; 
    s21_size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp7) {
    const char *str1 = "apple";
    const char *str2 = "apricot"; 
    s21_size_t n = 20;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp8) {
    const char *str1 = "apple";
    const char *str2 = "applepie"; 
    s21_size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp9) {
    const char *str1 = "applepie";
    const char *str2 = "applecake"; 
    s21_size_t n = 6;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp10) {
    const char *str1 = "apple";
    const char *str2 = "apple"; 
    s21_size_t n = 0;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *suite_strncmp(void) {
    Suite *s = suite_create("strncmp");
    TCase *tc = tcase_create("strncmp_tc");

    tcase_add_test(tc, strncmp1);
    tcase_add_test(tc, strncmp2);
    tcase_add_test(tc, strncmp3);
    tcase_add_test(tc, strncmp4);
    tcase_add_test(tc, strncmp5);
    tcase_add_test(tc, strncmp6);
    tcase_add_test(tc, strncmp7);
    tcase_add_test(tc, strncmp8);
    tcase_add_test(tc, strncmp9);
    tcase_add_test(tc, strncmp10);

    suite_add_tcase(s, tc);
    return s;
}