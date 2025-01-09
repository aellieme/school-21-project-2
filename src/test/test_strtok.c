#include "test.h"



void assert_strtok(char *s1, char *s2, char *delim) {
  ck_assert_str_eq(strtok(s1, delim), s21_strtok(s2, delim));
}

START_TEST(strtok1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char delim[] = "!";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(strtok2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char delim[] = "\0";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(strtok3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char delim[] = " ";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(strtok4) {
  char s1[] = "Hello, \0world!";
  char s2[] = "Hello, \0world!";
  char delim[] = " ";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(strtok5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char delim[] = "o";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(strtok6) {
  char s1[] = "Hello, world!!!!!";
  char s2[] = "Hello, world!!!!!";
  char delim[] = "!";
  assert_strtok(s1, s2, delim);
}
END_TEST

START_TEST(strtok7) {
  char s1[] = "\0";
  char s2[] = "\0";
  char delim[] = " ";
  ck_assert_ptr_eq(strtok(s1, delim), s21_NULL);
  ck_assert_ptr_eq(strtok(s2, delim), s21_NULL);
}
END_TEST

Suite *suite_strtok(void){
    Suite *s = suite_create("strtok");
    TCase *tc = tcase_create("strtok_tc");
    
    tcase_add_test(tc, strtok1);
    tcase_add_test(tc, strtok2);
    tcase_add_test(tc, strtok3);
    tcase_add_test(tc, strtok4);
    tcase_add_test(tc, strtok5);
    tcase_add_test(tc, strtok6);
    tcase_add_test(tc, strtok7);

    suite_add_tcase(s, tc);
    return s;
}