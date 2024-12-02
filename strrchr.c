// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
#include <stdio.h>
#include <string.h>

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

int main() {
  const char *str = "hello, world!";
  char symbol = 'e';

  char *result = s21_strrchr(str, symbol);
  if (result != s21_NULL) {
    printf("Последний символ '%c' найден по адресу: %p\n", symbol, result);
  } else {
    printf("Символ '%c' не найден в строке.\n", symbol);
  }

  char *result2 = strrchr(str, symbol);
  if (result != NULL) {
    printf("Последний символ '%c' найден по адресу: %p\n", symbol, result2);
  } else {
    printf("Символ '%c' не найден в строке.\n", symbol);
  }

  return 0;
}