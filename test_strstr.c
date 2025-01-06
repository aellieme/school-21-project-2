#include "test.h"

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

START_TEST(strstr_10) {
  char *s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = "XYZ";
  char *s3 = "";
  ck_assert_ptr_eq(strstr(s1, s2), s21_strstr(s1, s2));
  ck_assert_ptr_eq(strstr(s3, s2), s21_strstr(s3, s2));
  ck_assert_ptr_eq(strstr(s1, s3), s21_strstr(s1, s3));
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
  tcase_add_test(tc, strstr_10);
  
  suite_add_tcase(s, tc);
  return s;
}