#include "test.h"


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

Suite *suite_strchr(void) 
{
    Suite *s = suite_create("strchr");
    TCase *tc = tcase_create("strchr_tc");
    
    tcase_add_test(tc, strchr1);
    tcase_add_test(tc, strchr2);
    tcase_add_test(tc, strchr3);
    tcase_add_test(tc, strchr4);
    tcase_add_test(tc, strchr5);
    tcase_add_test(tc, strchr6);
    tcase_add_test(tc, strchr7);
    tcase_add_test(tc, strchr8);
    tcase_add_test(tc, strchr9);

    suite_add_tcase(s, tc);
    return s;
}
