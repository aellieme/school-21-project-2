#include "test.h"



START_TEST(trim1)
{
#line 7
const char *src = "   Hello, peace, sun, sea!   ";
const char *trim_chars = " ";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello, peace, sun, sea!");
free(result);

}
END_TEST

START_TEST(trim2)
{
#line 15
const char *src = "";
const char *trim_chars = " ";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "");
free(result);

}
END_TEST

START_TEST(trim3)
{
#line 23
const char *src = "Hello\0world!";
const char *trim_chars = " ";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello\0world!");
free(result);

}
END_TEST

START_TEST(trim4)
{
#line 31
const char *src = "    ";
const char *trim_chars = " ";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "");
free(result);

}
END_TEST

START_TEST(trim5)
{
#line 39
const char *src = " \t\nHello, world!\t\n ";
const char *trim_chars = " \t\n";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello, world!");
free(result);

}
END_TEST

START_TEST(trim6)
{
#line 47
const char *src = "Hello\0world!";
const char *trim_chars = " \0";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello\0world!");
free(result);

}
END_TEST

START_TEST(trim7)
{
#line 55
const char *src = "abcHello, world!cba";
const char *trim_chars = "abc";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello, world!");
free(result);

}
END_TEST

START_TEST(trim8)
{
#line 63
const char *src = "!!!Hello, world!!!";
const char *trim_chars = "!";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello, world");
free(result);

}
END_TEST

START_TEST(trim9)
{
#line 71
const char *src = "12345";
const char *trim_chars = "12345";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "");
free(result);

}
END_TEST

START_TEST(trim10)
{
#line 79
const char *src = "12345Hello, world!12345";
const char *trim_chars = "12345";
char *result = (char *)s21_trim(src, trim_chars);
ck_assert_ptr_ne(result, s21_NULL);
ck_assert_str_eq(result, "Hello, world!");
free(result);
}
END_TEST

Suite *suite_trim(void)
{
    Suite *s = suite_create("trim");
    TCase *tc = tcase_create("trim_tc");
   
    tcase_add_test(tc, trim1);
    tcase_add_test(tc, trim2);
    tcase_add_test(tc, trim3);
    tcase_add_test(tc, trim4);
    tcase_add_test(tc, trim5);
    tcase_add_test(tc, trim6);
    tcase_add_test(tc, trim7);
    tcase_add_test(tc, trim8);
    tcase_add_test(tc, trim9);
    tcase_add_test(tc, trim10);

   
    suite_add_tcase(s, tc);
    return s;
}
