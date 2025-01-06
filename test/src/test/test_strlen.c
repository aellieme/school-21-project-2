#include "test.h"



START_TEST(strlen1)
{
#line 7
char string[]="Hello, world!";
ck_assert_int_eq(strlen(string), s21_strlen(string));

}
END_TEST

START_TEST(strlen2)
{
#line 7
char string[]=" ";
ck_assert_int_eq(strlen(string), s21_strlen(string));

}
END_TEST

START_TEST(strlen3)
{
#line 7
char string[]="\0";
ck_assert_int_eq(strlen(string), s21_strlen(string));

}
END_TEST

START_TEST(strlen4)
{
#line 7
char string[]="\n";
ck_assert_int_eq(strlen(string), s21_strlen(string));

}
END_TEST

START_TEST(strlen5)
{
#line 7
char string[]="Hello, world!";
ck_assert_int_eq(strlen(string), s21_strlen(string));

}
END_TEST


Suite *suite_strlen(void)
{
    Suite *s = suite_create("strlen");
    TCase *tc = tcase_create("strlen_tc");
    

    tcase_add_test(tc, strlen1);
    tcase_add_test(tc, strlen2);
    tcase_add_test(tc, strlen3);
    tcase_add_test(tc, strlen4);
    tcase_add_test(tc, strlen5);
    
    
    suite_add_tcase(s, tc);
    return s;
}
