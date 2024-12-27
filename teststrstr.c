#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strstr.h"  // Убедитесь, что здесь определена s21_strstr

void assert_strstr(const char *haystack, const char *needle) {
    const char *expected = strstr(haystack, needle);
    const char *result = s21_strstr(haystack, needle);
    ck_assert_str_eq(expected, result);  // Сравниваем строки, а не указатели
}

START_TEST(strstr1) {
    char string[12] = "hello world";
    char needle[6] = "world";
    assert_strstr(string, needle);  
}
END_TEST

START_TEST(strstr2) {
    char string[12] = "hello world";
    char needle[6] = "!";
    assert_strstr(string, needle);  // Передаем обе строки
}
END_TEST

START_TEST(strstr3) {
    char string[12] = "hello world";
    char needle[6] = "cat";
    assert_strstr(string, needle);  // Передаем обе строки
}
END_TEST

START_TEST(strstr4) {
    char string[20] = "25 25 25 25 6 25 25";
    char needle[6] = "6";
    assert_strstr(string, needle);  // Передаем обе строки
}
END_TEST

START_TEST(strstr5) {
    char string[12] = "hello world";
    char needle[6] = " ";
    assert_strstr(string, needle);  // Передаем обе строки
}
END_TEST

START_TEST(strstr6) {
    char string[12] = "hello world";
    char needle[6] = "\0";
    assert_strstr(string, needle);  // Передаем обе строки
}
END_TEST

START_TEST(strstr7) {
    char string[12] = "hello world";
    char needle[6] = "or\0ld";
    assert_strstr(string, needle);  
}
END_TEST

START_TEST(strstr8) {
    char string[25] = "helloor\0ld world";
    char needle[6] = "world";
    assert_strstr(string, needle);  
}
END_TEST

START_TEST(strstr9) {
    char string[12] = "    ";
    char needle[6] = "  ";
    assert_strstr(string, needle);  
}
END_TEST


int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    //добавляю тесты
    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, strstr1);
    tcase_add_test(tc1_1, strstr2);
    tcase_add_test(tc1_1, strstr3);
    tcase_add_test(tc1_1, strstr4);
    tcase_add_test(tc1_1, strstr5);
    tcase_add_test(tc1_1, strstr6);
    tcase_add_test(tc1_1, strstr7);
    tcase_add_test(tc1_1, strstr8);
    tcase_add_test(tc1_1, strstr9);

    srunner_run_all(sr, CK_NORMAL);  // Исправлено на CK_NORMAL
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}