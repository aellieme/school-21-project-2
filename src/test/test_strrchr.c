#include "test.h"



START_TEST(strrchr1)
{
#line 8
const char *str = "hello, world!";
char symbol = 'e';
ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

START_TEST(strrchr2)
{
#line 13
const char *str = "hello, world!";
char symbol = 'o';
ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

START_TEST(strrchr3)
{
#line 18
const char *str = "hello, world!";
char symbol = '!';
ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

// START_TEST(strrchr4)
// {
// #line 23
// const char *str = "hello, world!";
// char symbol = 'h';
// ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

// }
// END_TEST

START_TEST(strrchr5)
{
#line 28
const char *str = "hello, world!";
char symbol = 'p';
ck_assert_ptr_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

// START_TEST(strrchr6)
// {
// #line 33
// const char *str = "cat";
// char symbol = '\0';
// ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str, symbol));

// }
// END_TEST

START_TEST(strrchr7)
{
#line 38
const char *str = "";
char symbol = 'e';
ck_assert_ptr_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

START_TEST(strrchr8)
{
#line 43
const char *str = "hello, world!";
char symbol = ' ';
ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

START_TEST(strrchr9)
{
#line 48
const char *str = "1234567890";
char symbol = '5';
ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

START_TEST(strrchr10)
{
#line 53
const char *str = "hello, world!";
char symbol = ',';
ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));

}
END_TEST

START_TEST(strrchr11)
{
#line 58
const char *str = "hello, world!";
char symbol = 'l';
ck_assert_str_eq(strrchr(str, symbol), s21_strrchr(str,symbol));
}
END_TEST

Suite *suite_strrchr(void)
{
    Suite *s = suite_create("strrchr");
    TCase *tc = tcase_create("strrchr_tc");
    

    tcase_add_test(tc, strrchr1);
    tcase_add_test(tc, strrchr2);
    tcase_add_test(tc, strrchr3);
    //tcase_add_test(tc, strrchr4);
    tcase_add_test(tc, strrchr5);
    //tcase_add_test(tc, strrchr6);
    tcase_add_test(tc, strrchr7);
    tcase_add_test(tc, strrchr8);
    tcase_add_test(tc, strrchr9);
    tcase_add_test(tc, strrchr10);
    tcase_add_test(tc, strrchr11);

    suite_add_tcase(s, tc);
    return s;
}

