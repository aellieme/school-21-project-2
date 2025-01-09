#include "test.h"



START_TEST(strcspn1)
{
#line 8
const char *str1 = "hello world";
const char *str2 = "bacgv";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn2)
{
#line 14
const char *str1 = "hello \0world";
const char *str2 = "bacgv";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn3)
{
#line 20
const char *str1 = "hello world";
const char *str2 = "bacg\0v";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn4)
{
#line 26
const char *str1 = "vdmvlkfdnfvlkndvlk";
const char *str2 = "l";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn5)
{
#line 32
const char *str1 = "12356874";
const char *str2 = "6";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn6)
{
#line 38
const char *str1 = "\0hello world";
const char *str2 = "bacgv";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn7)
{
#line 44
const char *str1 = "";
const char *str2 = "bacgv";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn8)
{
#line 50
const char *str1 = "hello world";
const char *str2 = "";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn9)
{
#line 56
const char *str1 = "hello worldhello worldhello worldhello worldhello worldhello world";
const char *str2 = "bacgv";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn10)
{
#line 62
const char *str1 = "h";
const char *str2 = "";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));


}
END_TEST

START_TEST(strcspn11)
{
#line 68
const char *str1 = "";
const char *str2 = "k";
ck_assert_uint_eq(strcspn(str1, str2), s21_strcspn(str1,str2));
}
END_TEST

Suite *suite_strcspn(void)
{
    Suite *s = suite_create("strcspn");
    TCase *tc = tcase_create("strcspn_tc");
    
    
    tcase_add_test(tc, strcspn1);
    tcase_add_test(tc, strcspn2);
    tcase_add_test(tc, strcspn3);
    tcase_add_test(tc, strcspn4);
    tcase_add_test(tc, strcspn5);
    tcase_add_test(tc, strcspn6);
    tcase_add_test(tc, strcspn7);
    tcase_add_test(tc, strcspn8);
    tcase_add_test(tc, strcspn9);
    tcase_add_test(tc, strcspn10);
    tcase_add_test(tc, strcspn11);

   suite_add_tcase(s, tc);
    return s;
}
