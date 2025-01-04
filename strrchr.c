// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

char *s21_strrchr(const char *str, int c){
  const char *last_found = s21_NULL;

  // идем с конца строки вперед
  while (*str != '\0') {
    if (*str == (char)c) {
      last_found = str;  // запоминаем последнюю позицию символа
    }
    str++;
  }
  return (char *)last_found;
}