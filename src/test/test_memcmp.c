#include "test.h"


START_TEST(memcmp1)
{
const char str1[] = "hello";
const char str2[] = "hello";
s21_size_t size = 5;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 0);

}
END_TEST

START_TEST(memcmp2)
{
const char str1[] = "hello world";
const char str2[] = "hello cat";
s21_size_t size = 10;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 1);

}
END_TEST

START_TEST(memcmp3)
{
const char str1[] = "hello ";
const char str2[] = "hello cat, dog";
s21_size_t size = 7;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, -1);

}
END_TEST

START_TEST(memcmp4)
{
const char str1[] = "hello";
const char str2[] = "hello";
s21_size_t size = 0;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 0);

}
END_TEST

START_TEST(memcmp5)
{
const char str1[] = "cat";
const char str2[] = "cct";
s21_size_t size = 5;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, -1);

}
END_TEST

START_TEST(memcmp6)
{
const char str1[] = "he\0llo";
const char str2[] = "he\0llo";
s21_size_t size = 7;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 0);

}
END_TEST

START_TEST(memcmp7)
{
const char str1[] = "h\ello";
const char str2[] = "h\ello";
s21_size_t size = 5;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 0);

}
END_TEST

START_TEST(memcmp8)
{
const char str1[] = "hello";
const char str2[] = "hello";
s21_size_t size = 6;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 0);

}
END_TEST

START_TEST(memcmp9)
{

const char str1[] = "\fkkfdv\\kjf";
const char str2[] = "\fkkfdv\\kjf";
s21_size_t size = 5;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 0);

}
END_TEST

START_TEST(memcmp10)
{
const char str1[] = " ";
const char str2[] = "hello";
s21_size_t size = 0;

int result = s21_memcmp(str1, str2, size);
ck_assert_int_eq(result, 0);

}
END_TEST
Suite *suite_memcmp(void) {
    Suite *s1 = suite_create("\033[47;30mmemcmp\033[0m");
    TCase *tc = tcase_create("memcmp_tc");

    tcase_add_test(tc, memcmp1);
    tcase_add_test(tc, memcmp2);
    tcase_add_test(tc, memcmp3);
    tcase_add_test(tc, memcmp4);
    tcase_add_test(tc, memcmp5);
    tcase_add_test(tc, memcmp6);
    tcase_add_test(tc, memcmp7);
    tcase_add_test(tc, memcmp8);
    tcase_add_test(tc, memcmp9);
    tcase_add_test(tc, memcmp10);
    suite_add_tcase(s1, tc);

    return s1;
}