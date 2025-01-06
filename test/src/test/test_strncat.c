#include "test.h"



START_TEST(strncat1)
{
#line 8
char a[50] = "Hello";
const char b[] = "world!";
s21_size_t c = 4;
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));

}
END_TEST

START_TEST(strncat2)
{
#line 14
char a[50] = "Hello ";
const char b[] = "";
s21_size_t c = 0;
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));

}
END_TEST

START_TEST(strncat3)
{
#line 20
char a[50] = "Hello";
const char b[] = "wor\0ld!";
s21_size_t c = 6;
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));

}
END_TEST

START_TEST(strncat4)
{
#line 26
char a[50] = "Hello";
const char b[] = "\0world!";
s21_size_t c = 6;
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));

}
END_TEST

START_TEST(strncat5)
{
#line 32
char a[50] = "Hello";
const char b[] = "world!\0";
s21_size_t c = 6;
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));

}
END_TEST

START_TEST(strncat6)
{
#line 38
char a[50] = "Hello ";
const char b[] = "world!";
s21_size_t c =  strlen(b);
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));

}
END_TEST

START_TEST(strncat7)
{
#line 44
char a[50] = "Hello ";
const char b[] = "world!";
s21_size_t c = 3;
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));

}
END_TEST

START_TEST(strncat8)
{
#line 50
char a[50] = "12,15, ";
const char b[] = "18";
s21_size_t c = 3;
ck_assert_str_eq(strncat(a, b , c), s21_strncat(a,b, c));


 
}
END_TEST

Suite *suite_strncat(void) {
    Suite *s = suite_create("strncat");
    TCase *tc = tcase_create("strncat_tc");

    tcase_add_test(tc, strncat1);
    tcase_add_test(tc, strncat2);
    tcase_add_test(tc, strncat3);
    tcase_add_test(tc, strncat4);
    tcase_add_test(tc, strncat5);
    tcase_add_test(tc, strncat6);
    tcase_add_test(tc, strncat7);
    tcase_add_test(tc, strncat8);

    suite_add_tcase(s, tc);
    return s;
}
