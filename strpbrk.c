// Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
#include <stdio.h>
#include <string.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

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
int main() {
  const char *str1 = "Hello, world!";
  const char *str2 = "Yallo Store";

  char *result = s21_strpbrk(str1, str2);

  if (result != s21_NULL) {
    printf("Первый найденный символ: %c\n", *result);
  } else {
    printf("Совпадающих символов нет.\n");
  }

    char *result2=strpbrk(str1,str2);
    if (result != NULL) {
      printf("Первый найденный символ: %c\n", *result2);
    } else {
      printf("Совпадающих символов нет.\n");
    }

  return 0;
}