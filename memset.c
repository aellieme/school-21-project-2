// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.

// str — указатель на область памяти, которую нужно заполнить.
// value — значение,которым нужно заполнить память.
// volume — количество байт,которые нужно заполнить.

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

void *s21_memset(void *str, int value, s21_size_t volume) {
    
    for (s21_size_t i=0; i<volume; i++){
      ((unsigned char *)str)[i] = value;
    }
    return str;
}

int main() {
  char buffer[10];
  //заполняем цифрой 5
  s21_memset(buffer, 5 , sizeof(buffer));

  printf("Buffer after memset: ");
  for (int s21_size_t i = 0; i < sizeof(buffer); i++) {
    printf("%d", buffer[i]);
  }
  return 0;
}