/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "a.check" instead.
 */

#include <check.h>

#line 1 "a.check"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strchr.h"


START_TEST(strchr1)
{
#line 8
const char str[] = "Hello, world!";
char c = 'H';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr2)
{
#line 13
const char str[] = "Hello, world!";
char c = 'e';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr3)
{
#line 18
const char str[] = "Hello, world!";
char c = '!';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr4)
{
#line 23
const char str[] = "Hello, world!";
char c = ' ';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr5)
{
#line 28
const char str[] = "Hello, world!";
char c = 'z';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr6)
{
#line 33
const char str[] = "Hello, world!";
char c = '\0';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr7)
{
#line 38
const char str[] = "Hello, world!";
char c = ',';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr8)
{
#line 43
const char str[] = "Hello, world!";
char c = {15};
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));

}
END_TEST

START_TEST(strchr9)
{
#line 48
const char str[] = "Hello, world!";
char c = 'l';
ck_assert_ptr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, strchr1);
    tcase_add_test(tc1_1, strchr2);
    tcase_add_test(tc1_1, strchr3);
    tcase_add_test(tc1_1, strchr4);
    tcase_add_test(tc1_1, strchr5);
    tcase_add_test(tc1_1, strchr6);
    tcase_add_test(tc1_1, strchr7);
    tcase_add_test(tc1_1, strchr8);
    tcase_add_test(tc1_1, strchr9);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
