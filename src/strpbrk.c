// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
#include <stdio.h>
#include "s21_string.h"


char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int found = 0;

  for (int count= 0; *str1 != '\0'; str1++) {
    for (const char *ptr = str2; *ptr != '\0' && !found; ptr++) {
      if (*str1 == *ptr) {
        result = (char *)str1;
        found = 1;
      }
    }
    count++;
  }

  return result;
}