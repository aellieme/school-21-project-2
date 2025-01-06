// #define NULL ((void*)0); //в интернете написано что это определение нулевого
// указателя
// // string – указатель на область памяти, где будет производиться поиск.
// // item – символ, который нужно найти.
// count – количество байт,которые будут проверены начиная с позиции, указанной
// параметром string

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

void *s21_memchr(const void *string, int item, s21_size_t count) {
  void *return_value = s21_NULL;
  for (s21_size_t i = 0; i < count && return_value == s21_NULL; i++) {
    if (*(unsigned char *)(string + i) == (unsigned char)item) {
      return_value = (void *)(string + i);
    }
  }
  return return_value;
}