#include "test.h"

START_TEST(strncpy1)
{
#line 8
char str_to[20] = {0};
const char *str_from = "Hello, World!"; 
s21_size_t n = 5 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));


}
END_TEST

START_TEST(strncpy2)
{
#line 15
char str_to[20] = {0};
const char *str_from =""; 
s21_size_t n = 5 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));


}
END_TEST

START_TEST(strncpy3)
{
#line 22
char str_to[20] = {0};
const char *str_from = "Hello, World!"; 
s21_size_t n = 20 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));


}
END_TEST

START_TEST(strncpy4)
{
#line 29
char str_to[20] = {0};
const char *str_from = "Hello, World!"; 
s21_size_t n = 13 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));


}
END_TEST

START_TEST(strncpy5)
{
#line 36
char str_to[20] = {0};
const char *str_from = "Hello, \0World!"; 
s21_size_t n = 5 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));


}
END_TEST

START_TEST(strncpy6)
{
#line 43
char str_to[20] = {0};
const char *str_from = "This is a long string"; 
s21_size_t n = 20 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));


}
END_TEST

START_TEST(strncpy7)
{
#line 50
char str_to[20] = {0};
const char *str_from = "\0This is a long string"; 
s21_size_t n = 20 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));


}
END_TEST

START_TEST(strncpy8)
{
#line 57
char str_to[20] = {0};
const char *str_from = "This is a long string\0"; 
s21_size_t n = 20 ;
ck_assert_str_eq(strncpy(str_to, str_from, n), s21_strncpy(str_to, str_from, n));

}
END_TEST

Suite *suite_strncpy(void)
{
    Suite *s = suite_create("strncpy");
    TCase *tc = tcase_create("strncpy_tc");
    
    tcase_add_test(tc, strncpy1);
    tcase_add_test(tc, strncpy2);
    tcase_add_test(tc, strncpy3);
    tcase_add_test(tc, strncpy4);
    tcase_add_test(tc, strncpy5);
    tcase_add_test(tc, strncpy6);
    tcase_add_test(tc, strncpy7);
    tcase_add_test(tc, strncpy8);

     
    suite_add_tcase(s, tc);
    return s;
}
