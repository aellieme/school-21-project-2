// Копирует до n символов из строки str_from, в str_to.
#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

char *s21_strncpy(char *str_to, const char *str_from, s21_size_t n){
    if (str_to == s21_NULL || str_from == s21_NULL) {
        str_to = s21_NULL;
    }

    else{

        s21_size_t i;

        for (i = 0; (i < n) && (str_from[i] != '\0'); i++) {
            str_to[i] = str_from[i];
            }
        for (s21_size_t j = i ; j < n; j++) {
            str_to[j] = '\0';
            }
    }
    return str_to;
}



int main() {
  const char *source = "Hello, World!";
  char destination[20];  

  s21_strncpy(destination, source, 13);

  printf("Source string: %s\n", source);
  printf("Destination string: %s", destination);

  return 0;
}