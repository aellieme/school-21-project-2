#include "test.h"


START_TEST(sprintf1) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%s";
    const char *val = "Testing basic string";
    int res1 = s21_sprintf(str1, format, val);
    int res2 = sprintf(str2, format, val);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%+d % d %-d";
    int res1 = s21_sprintf(str1, format, 123, -456, 789);
    int res2 = sprintf(str2, format, 123, -456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.2f %.5f %.0f";
    int res1 = s21_sprintf(str1, format, 123.456, 0.123456, 789.987);
    int res2 = sprintf(str2, format, 123.456, 0.123456, 789.987);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%5c %-5c";
    int res1 = s21_sprintf(str1, format, 'a', 'b');
    int res2 = sprintf(str2, format, 'a', 'b');
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf5) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%10.5s %-10.5s";
    int res1 = s21_sprintf(str1, format, "testing", "strings");
    int res2 = sprintf(str2, format, "testing", "strings");
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%u %5u %.5u";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%hd %ld";
    short sh = 123;
    long lg = 456789L;
    int res1 = s21_sprintf(str1, format, sh, lg);
    int res2 = sprintf(str2, format, sh, lg);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%d %f %s %c %u";
    int res1 = s21_sprintf(str1, format, 123, 456.789, "test", 'x', 987);
    int res2 = sprintf(str2, format, 123, 456.789, "test", 'x', 987);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf9) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.5d %.0d %.5d";
    int res1 = s21_sprintf(str1, format, 123, 0, -456);
    int res2 = sprintf(str2, format, 123, 0, -456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf10) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%10d %-10d %010d";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_i) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%i %i %i";
    int res1 = s21_sprintf(str1, format, 123, -456, 0);
    int res2 = sprintf(str2, format, 123, -456, 0);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_e) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3e %.5e";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_E) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3E %.5E";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_g) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3g %.5g";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_G) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3G %.5G";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_o) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%o %o %o";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_x) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%x %x %x";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_X) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%X %X %X";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_p) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    int x = 42;
    const char *format = "%p";
    int res1 = s21_sprintf(str1, format, &x);
    int res2 = sprintf(str2, format, &x);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_n) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    int count1 = 0, count2 = 0;
    const char *format = "Hello, world!%n";
    s21_sprintf(str1, format, &count1);
    sprintf(str2, format, &count2);
    ck_assert_int_eq(count1, count2);
    ck_assert_str_eq(str1, str2);
}
END_TEST



Suite *suite_sprintf(void) {
    Suite *s = suite_create("sprintf");
    TCase *tc = tcase_create("sprintf_tc");

    tcase_add_test(tc, sprintf1);
    tcase_add_test(tc, sprintf2);
    tcase_add_test(tc, sprintf3);
    tcase_add_test(tc, sprintf4);
    tcase_add_test(tc, sprintf5);
    tcase_add_test(tc, sprintf6);
    tcase_add_test(tc, sprintf7);
    tcase_add_test(tc, sprintf8);
    tcase_add_test(tc, sprintf9);
    tcase_add_test(tc, sprintf10);
    tcase_add_test(tc, sprintf_i);
    tcase_add_test(tc, sprintf_e);
    tcase_add_test(tc, sprintf_E);
    tcase_add_test(tc, sprintf_g);
    tcase_add_test(tc, sprintf_G);
    tcase_add_test(tc, sprintf_o);
    tcase_add_test(tc, sprintf_x);
    tcase_add_test(tc, sprintf_X);
    tcase_add_test(tc, sprintf_p);
    tcase_add_test(tc, sprintf_n);
    suite_add_tcase(s, tc);
    return s;
}