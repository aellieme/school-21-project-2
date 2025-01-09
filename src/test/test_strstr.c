#include "../test.h"

START_TEST(strstr_1) {
  char str[] = "Learning C is fun!";
  char str1[] = "C";
  ck_assert_str_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_2) {
  char str[] = " \t\n\0";
  char str1[] = "\t\n";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_3) {
  char str[] = "Empty string";
  char str1[] = "nonexistent";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_4) {
  char str[] = "This is a test.";
  char str1[] = "is a";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_5) {
  char str[] = "Case sensitivity test";
  char str1[] = "case";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_6) {
  char str[] = "Leading space";
  char str1[] = " ";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_7) {
  char str[] = "Hello World";
  char str1[] = "World!";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_8) {
  char str[] = "String with special characters: @#$%&*";
  char str1[] = "@#$";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

START_TEST(strstr_9) {
  char str[] = "Repeated words words words";
  char str1[] = "words";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST



START_TEST(strstr_12) {
  char haystack[] = "No match here";
  char needle[] = "match";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST




START_TEST(strstr_15) {
  char haystack[] = "Numbers: 123 456 789";
  char needle[] = "456";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_16) {
  char haystack[] = "Single character: A";
  char needle[] = "A";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_17) {
  char haystack[] = "-";
  char needle[] = "-";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_18) {
  char str[] = "Hello World";
  char str1[] = "Hell";
  ck_assert_ptr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST


Suite *suite_strstr(void) {
    Suite *s = suite_create("strstr");
    TCase *tc = tcase_create("strstr_tc");
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  
  tcase_add_test(tc, strstr_12);
  
  tcase_add_test(tc, strstr_15);
  tcase_add_test(tc, strstr_16);
  tcase_add_test(tc, strstr_17);
  tcase_add_test(tc, strstr_18);
  
  suite_add_tcase(s, tc);
  return s;
}