#include "test.h"


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


Suite *suite_strstr(void){
    Suite *s = suite_create("strstr");
    TCase *tc = tcase_create("strstr_tc");
    

    
    tcase_add_test(tc, strstr1);
    tcase_add_test(tc, strstr2);
    tcase_add_test(tc, strstr3);
    tcase_add_test(tc, strstr4);
    tcase_add_test(tc, strstr5);
    tcase_add_test(tc, strstr6);
    tcase_add_test(tc, strstr7);
    tcase_add_test(tc, strstr8);
    tcase_add_test(tc, strstr9);

    suite_add_tcase(s, tc);
    return s;
}