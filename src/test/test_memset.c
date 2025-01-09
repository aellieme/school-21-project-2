#include "test.h"


START_TEST(memset1) {
#line 8
    char a[] = "Hello";
    s21_size_t c = 5;
    char value = 'A';
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset2) {
#line 15
    char a[10];
    s21_size_t c = 5;
    char value = 'x';
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset3) {
#line 22
    char a[10] = {0};
    s21_size_t c = 5;
    char value = 'A';
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset4) {
#line 29
    char a[] = "Hello";
    s21_size_t c = 5;
    char value = '\0';
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset5) {
#line 36
    char a[10] = {0};
    s21_size_t c = 10;
    char value = 'p';
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset6) {
#line 43
    char a[10] = "Hello";
    s21_size_t c = 1;
    char value = 'p';
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset7) {
#line 50
    char a[10] = "Hello";
    s21_size_t c = 5;
    char value = -1;
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset8) {
#line 57
    char a[100] = {0};
    s21_size_t c = 1;
    char value = 'F';
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

START_TEST(memset9) {
#line 64
    char a[10] = {0};
    s21_size_t c = 5;
    char value = 128;
    ck_assert_str_eq(memset(a, value, c), s21_memset(a, value, c));
}
END_TEST

Suite *suite_memset(void) {
    Suite *s = suite_create("memset");
    TCase *tc = tcase_create("memset_tc");

    tcase_add_test(tc, memset1);
    tcase_add_test(tc, memset2);
    tcase_add_test(tc, memset3);
    tcase_add_test(tc, memset4);
    tcase_add_test(tc, memset5);
    tcase_add_test(tc, memset6);
    tcase_add_test(tc, memset7);
    tcase_add_test(tc, memset8);
    tcase_add_test(tc, memset9);

    suite_add_tcase(s, tc);
    return s;
}