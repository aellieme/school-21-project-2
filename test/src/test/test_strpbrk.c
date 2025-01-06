#include "test.h"


START_TEST(strpbrk1)
{
#line 8
const char *str1 = "Hello, world!";
const char *str2 = "Yallo Store";
ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk2)
{
#line 14
const char *str1 = "Hello, world!";
const char *str2 = ",!";
ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk3)
{
#line 20
const char *str1 = "Hello, world!";
const char *str2 = "H";
ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk4)
{
#line 26
const char *str1 = "Hello, world!";
const char *str2 = "tar";
ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk5)
{
#line 32
const char *str1 = "";
const char *str2 = "Yallo Store";
ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk6)
{
#line 38
const char *str1 = "Hello, world!";
const char *str2 = "";
ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk7)
{
#line 44
const char *str1 = "Hello, world!";
const char *str2 = "oe";
ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk8)
{
#line 50
const char *str1 = "Hello, world!";
const char *str2 = "\0";
ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk9)
{
#line 56
const char *str1 = "Hell\0o, world!";
const char *str2 = "Yallo Store";
ck_assert_str_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));


}
END_TEST

START_TEST(strpbrk10)
{
#line 62
const char *str1 = "Hello, world!";
const char *str2 = "\0Yallo Store";
ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1,str2));
}
END_TEST

Suite *suite_strpbrk(void)
{
    Suite *s = suite_create("strpbrk");
    TCase *tc = tcase_create("strpbrk_tc");
   
    tcase_add_test(tc, strpbrk1);
    tcase_add_test(tc, strpbrk2);
    tcase_add_test(tc, strpbrk3);
    tcase_add_test(tc, strpbrk4);
    tcase_add_test(tc, strpbrk5);
    tcase_add_test(tc, strpbrk6);
    tcase_add_test(tc, strpbrk7);
    tcase_add_test(tc, strpbrk8);
    tcase_add_test(tc, strpbrk9);
    tcase_add_test(tc, strpbrk10);

    
    suite_add_tcase(s, tc);
    return s;
}

