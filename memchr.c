// #define NULL ((void*)0); //в интернете написано что это определение нулевого
// указателя
// // string – указатель на область памяти, где будет производиться поиск.
// // item – символ, который нужно найти.
// count – количество байт,которые будут проверены начиная с позиции, указанной
// параметром string

#include "s21_string.h"

void *s21_memchr(const void *string, int item, s21_size_t count) {
  void *return_value = s21_NULL;
  for (s21_size_t i = 0; i < count && return_value == s21_NULL; i++) {
    if (*(unsigned char *)(string + i) == (unsigned char)item) {
      return_value = (void *)(string + i);
    }
  }
  return return_value;
}

int main_s21_memchr() {
  char str[] = "Hello, world!";
  void *result = s21_memchr(str, 'o', sizeof(str));

  if (result != s21_NULL) {
    printf("Первое появление 'o' обнаружено по адресу %p\n", result);
  } else {
    printf("Не найдено.\n");
  }
  return 0;
}
