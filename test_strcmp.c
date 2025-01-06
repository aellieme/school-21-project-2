#include "test.h"


START_TEST(strcmp1) {
    const char *str1 = "applepie";
    const char *str2 = "apricot"; 
    size_t n = 4;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp2) {
    const char *str1 = "apple\0pie";
    const char *str2 = "apple\0fruit"; 
    size_t n = 6;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp3) {
    const char *str1 = "apple";
    const char *str2 = "apple"; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp4) {
    const char *str1 = "apple";
    const char *str2 = "apples"; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp5) {
    const char *str1 = "apple";
    const char *str2 = "apple"; 
    size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp6) {
    const char *str1 = "apple";
    const char *str2 = "banana"; 
    size_t n = 3;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp7) {
    const char *str1 = "apple";
    const char *str2 = "apricot"; 
    size_t n = 0;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp8) {
    const char *str1 = "apple\0pie";
    const char *str2 = "apple\0fruit"; 
    size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp9) {
    const char *str1 = "";
    const char *str2 = ""; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp10) {
    const char *str1 = "apple";
    const char *str2 = "APPLE"; 
    size_t n = 5;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp11) {
    const char *str1 = "apple\0pie";
    const char *str2 = "apple\0pie"; 
    size_t n = 10;
    ck_assert_int_eq(strncmp(str1, str2, n), s21_strncmp(str1, str2, n));
}
END_TEST

Suite *suite_strcmp(void) {
    Suite *s = suite_create("strcmp");
    TCase *tc = tcase_create("strcmp_tc");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, strcmp1);
    tcase_add_test(tc, strcmp2);
    tcase_add_test(tc, strcmp3);
    tcase_add_test(tc, strcmp4);
    tcase_add_test(tc, strcmp5);
    tcase_add_test(tc, strcmp6);
    tcase_add_test(tc, strcmp7);
    tcase_add_test(tc, strcmp8);
    tcase_add_test(tc, strcmp9);
    tcase_add_test(tc, strcmp10);
    tcase_add_test(tc, strcmp11);

    
    suite_add_tcase(s, tc);
    return s;
}