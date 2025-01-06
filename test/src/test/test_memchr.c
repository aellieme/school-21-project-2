#include "test.h"



START_TEST(memchr1)
{
    const char *string = "Hello, world!";
    int item = 'o';
    size_t count = strlen(string);
    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);
    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr2)
{
    const char *string = "Hello, world!";
    int item = 'o';
    size_t count = strlen(string);

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr3)
{
const char *string = "Hello, \0world!";
    int item = '\0';
    size_t count = strlen(string) + 7;

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);    

}
END_TEST

START_TEST(memchr4)
{
const char *string = "Hello, world!";
    int item = 'o';
    size_t count = strlen(string);

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr5)
{
const char *string = "Hello, world!";
    int item = 'o';
    size_t count = strlen(string);

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr6)
{
const char *string = "Hello, world!";
    int item = 'o';
    size_t count = strlen(string);

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr7)
{
const char *string = "Hello, world!";
    int item = 'o';
    size_t count = strlen(string);

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr8)
{
const char *string = "12547945325\063256";
    int item = '6';
    size_t count = strlen(string);

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr9)
{
const char *string = " ";
    int item = '6';
    size_t count = strlen(string);

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr10)
{
const char *string = "Hello, cat!";
    int item = 't';
    size_t count = 60 ;

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);

}
END_TEST

START_TEST(memchr11)
{
const char *string = "Hello, \0cat!";
    int item = 't';
    size_t count = strlen(string) + 10;

    void *result1 = memchr(string, item, count);
    void *result2 = s21_memchr(string, item, count);

    ck_assert_ptr_eq(result1, result2);
}
END_TEST

Suite *suite_memchr(void) {
   Suite *s = suite_create("\033[47;30mmemchr\033[0m");
   TCase *tc = tcase_create("memchr_tc");

    tcase_add_test(tc, memchr1);
    tcase_add_test(tc, memchr2);
    tcase_add_test(tc, memchr3);
    tcase_add_test(tc, memchr4);
    tcase_add_test(tc, memchr5);
    tcase_add_test(tc, memchr6);
    tcase_add_test(tc, memchr7);
    tcase_add_test(tc, memchr8);
    tcase_add_test(tc, memchr9);
    tcase_add_test(tc, memchr10);
    tcase_add_test(tc, memchr11);
    suite_add_tcase(s, tc);

    return s;
}