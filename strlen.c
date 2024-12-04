#include "s21_string.h"

s21_size_t s21_strlen(const char *string){
    s21_size_t i=0;
    while (string[i]!='\0'){
        i++;
    }
    return i;
}

int main_s21_strlen() {
  char str[] = "Hello, world!";
  s21_size_t result = s21_strlen(str);
    printf("длина строки %llu\n", result);
  return 0;
}
