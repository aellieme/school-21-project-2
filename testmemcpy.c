/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "a.check" instead.
 */

#include <check.h>

#line 1 "a.check"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "py.h"


START_TEST(memcpy1)
{
    char a[] = "Hello";
    const char b[] = "cat";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy2)
{
    char a[] = "Hello";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy3)
{
    char a[] = "";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy4)
{
    char a[] = "Hello";
    const char b[100] = "test";
    s21_size_t c = 0;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy5)
{
    char a[] = " ";
    const char b[] = "grep";
    s21_size_t c = 6;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy6)
{
    char a[] = "Hel\0lo";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy7)
{
    char a[5] = {1, 2, 3, 4, 5};
    const char b[5] = {6, 7, 8, 9, 10};
    s21_size_t c = sizeof(a);
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy8)
{
    char a[10000];
    char b[10000];
    memset(b, 'a', sizeof(b));
    s21_size_t c = sizeof(a);
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy9)
{
    char a[] = {1, 2, 3, 4, 5};
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy10)
{
    char a[10] = "H";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, memcpy1);
    tcase_add_test(tc1_1, memcpy2);
    tcase_add_test(tc1_1, memcpy3);
    tcase_add_test(tc1_1, memcpy4);
    tcase_add_test(tc1_1, memcpy5);
    tcase_add_test(tc1_1, memcpy6);
    tcase_add_test(tc1_1, memcpy7);
    tcase_add_test(tc1_1, memcpy8);
    tcase_add_test(tc1_1, memcpy9);
    tcase_add_test(tc1_1, memcpy10);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}