#include "test.h"

START_TEST(test_basic_string) {
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

START_TEST(test_integer_variations) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%+d % d %-d";
    int res1 = s21_sprintf(str1, format, 123, -456, 789);
    int res2 = sprintf(str2, format, 123, -456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_float_precision) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.2f %.5f %.0f";
    int res1 = s21_sprintf(str1, format, 123.456, 0.123456, 789.987);
    int res2 = sprintf(str2, format, 123.456, 0.123456, 789.987);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_char_width) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%5c %-5c";
    int res1 = s21_sprintf(str1, format, 'a', 'b');
    int res2 = sprintf(str2, format, 'a', 'b');
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_string_width_precision) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%10.5s %-10.5s";
    int res1 = s21_sprintf(str1, format, "testing", "strings");
    int res2 = sprintf(str2, format, "testing", "strings");
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_unsigned) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%u %5u %.5u";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_length_modifiers) {
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

START_TEST(test_mixed_specifiers) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%d %f %s %c %u";
    int res1 = s21_sprintf(str1, format, 123, 456.789, "test", 'x', 987);
    int res2 = sprintf(str2, format, 123, 456.789, "test", 'x', 987);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_precision_integers) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.5d %.0d %.5d";
    int res1 = s21_sprintf(str1, format, 123, 0, -456);
    int res2 = sprintf(str2, format, 123, 0, -456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_width_alignment) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%10d %-10d %010d";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_i) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%i %i %i";
    int res1 = s21_sprintf(str1, format, 123, -456, 0);
    int res2 = sprintf(str2, format, 123, -456, 0);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_e) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3e %.5e";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_E) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3E %.5E";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_g) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3g %.5g";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_G) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%.3G %.5G";
    int res1 = s21_sprintf(str1, format, 123.456, 0.000123456);
    int res2 = sprintf(str2, format, 123.456, 0.000123456);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_o) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%o %o %o";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_x) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%x %x %x";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_X) {
    char str1[BUFSIZ];
    char str2[BUFSIZ];
    const char *format = "%X %X %X";
    int res1 = s21_sprintf(str1, format, 123, 456, 789);
    int res2 = sprintf(str2, format, 123, 456, 789);
    ck_assert_int_eq(res1, res2);
    ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_specifier_p) {
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

START_TEST(test_specifier_n) {
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
    Suite *s = suite_create("suite_sprintf");
    TCase *tc = tcase_create("sprintf_tc");

    tcase_add_test(tc, test_basic_string);
    tcase_add_test(tc, test_integer_variations);
    tcase_add_test(tc, test_float_precision);
    tcase_add_test(tc, test_char_width);
    tcase_add_test(tc, test_string_width_precision);
    tcase_add_test(tc, test_unsigned);
    tcase_add_test(tc, test_length_modifiers);
    tcase_add_test(tc, test_mixed_specifiers);
    tcase_add_test(tc, test_precision_integers);
    tcase_add_test(tc, test_width_alignment);
    tcase_add_test(tc, test_specifier_i);
    tcase_add_test(tc, test_specifier_e);
    tcase_add_test(tc, test_specifier_E);
    tcase_add_test(tc, test_specifier_g);
    tcase_add_test(tc, test_specifier_G);
    tcase_add_test(tc, test_specifier_o);
    tcase_add_test(tc, test_specifier_x);
    tcase_add_test(tc, test_specifier_X);
    tcase_add_test(tc, test_specifier_p);
    tcase_add_test(tc, test_specifier_n);
    suite_add_tcase(s, tc);
    return s;
}