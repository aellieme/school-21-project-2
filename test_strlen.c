#include "../test.h"

// Тест для строки с NULL
START_TEST(strlen_null) {
  const char *str = NULL;
  s21_size_t result = 0;

  if (str == NULL) {
    result = 0;
  } else {
    result = s21_strlen(str);
  }

  ck_assert_int_eq(result, 0);
}
END_TEST

// Тест для строки с динамическим выделением памяти
START_TEST(strlen_dynamic) {
  char *str = malloc(100 * sizeof(char));
  memset(str, 'x', 99);
  str[99] = '\0';
  ck_assert_int_eq(strlen(str), s21_strlen(str));
  free(str);
}
END_TEST

// Тест для строки с очень длинным содержимым
START_TEST(strlen_very_long) {
  char *str = malloc(1000000 * sizeof(char));
  memset(str, 'a', 999999);
  str[999999] = '\0';
  ck_assert_int_eq(strlen(str), s21_strlen(str));
  free(str);
}
END_TEST

// Тест для строки с японскими символами (UTF-8)
START_TEST(strlen_japanese) {
  const char *str = "こんにちは世界"; // Японские символы
  size_t expected_len = strlen(str);
  ck_assert_int_eq(expected_len, s21_strlen(str));
}
END_TEST

// Тест для строки с арабскими символами
START_TEST(strlen_arabic) {
  const char *str = "مرحبا بالعالم"; // Арабские символы
  size_t expected_len = strlen(str);
  ck_assert_int_eq(expected_len, s21_strlen(str));
}
END_TEST

// Тест для строки с нестандартными символами
START_TEST(strlen_nonstandard_chars) {
  char str[] = "\xFF\xFE\xFD";
  size_t expected_len = strlen(str);
  ck_assert_int_eq(expected_len, s21_strlen(str));
}
END_TEST

// Тест для строки из одного символа
START_TEST(strlen_one_char) {
  char str[] = "A";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

// Тест для строки, полностью состоящей из символа `\0`
START_TEST(strlen_all_null) {
  char str[10] = {0};
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

// Тест для строки с границей ввода
START_TEST(strlen_boundary) {
  char str[2] = {'A', '\0'};
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *suite_strlen(void) {
  Suite *s =  suite_create("strlen");
  TCase *tc = tcase_create("strlen_tc");

  tcase_add_test(tc, strlen_null);
  tcase_add_test(tc, strlen_dynamic);
  tcase_add_test(tc, strlen_very_long);
  tcase_add_test(tc, strlen_japanese);
  tcase_add_test(tc, strlen_arabic);
  tcase_add_test(tc, strlen_nonstandard_chars);
  tcase_add_test(tc, strlen_one_char);
  tcase_add_test(tc, strlen_all_null);
  tcase_add_test(tc, strlen_boundary);

  suite_add_tcase(s, tc);
  return s;
}