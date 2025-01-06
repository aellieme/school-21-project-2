#include "test.h"




START_TEST(memcpy1)
{
    char a[] = "Hello";
    const char b[] = "cat";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy2)
{
    char a[] = "Hello";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy3)
{
    char a[] = "";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy4)
{
    char a[] = "Hello";
    const char b[100] = "test";
    s21_size_t c = 0;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy5)
{
    char a[] = " ";
    const char b[] = "grep";
    s21_size_t c = 6;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy6)
{
    char a[] = "Hel\0lo";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy7)
{
    char a[5] = {1, 2, 3, 4, 5};
    const char b[5] = {6, 7, 8, 9, 10};
    s21_size_t c = sizeof(a);
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy8)
{
    char a[10000];
    char b[10000];
    memset(b, 'a', sizeof(b));
    s21_size_t c = sizeof(a);
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy9)
{
    char a[] = {1, 2, 3, 4, 5};
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST

START_TEST(memcpy10)
{
    char a[10] = "H";
    const char b[100] = "test";
    s21_size_t c = 5;
    ck_assert_str_eq(memcpy(a, b, c), s21_memcpy(a, b, c));
}
END_TEST
Suite *suite_memcpy(void)
{
    Suite *s = suite_create("memcmpy");
    TCase *tc = tcase_create("memcmpy_tc");

    tcase_add_test(tc, memcpy1);
    tcase_add_test(tc, memcpy2);
    tcase_add_test(tc, memcpy3);
    tcase_add_test(tc, memcpy4);
    tcase_add_test(tc, memcpy5);
    tcase_add_test(tc, memcpy6);
    tcase_add_test(tc, memcpy7);
    tcase_add_test(tc, memcpy8);
    tcase_add_test(tc, memcpy9);
    tcase_add_test(tc, memcpy10);

    suite_add_tcase(s, tc);
    return s;
}