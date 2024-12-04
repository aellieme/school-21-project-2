// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.

// str — указатель на область памяти, которую нужно заполнить.
// value — значение,которым нужно заполнить память.
// volume — количество байт,которые нужно заполнить.

#include "s21_string.h"

void *s21_memset(void *str, int value, s21_size_t volume) {
    
    for (s21_size_t i=0; i<volume; i++){
      ((unsigned char *)str)[i] = value;
    }
    return str;
}

int main_s21_memset() {
  char buffer[10];
  //заполняем цифрой 5
  s21_memset(buffer, 5 , sizeof(buffer));

  printf("Buffer after memset: ");
  for (s21_size_t i = 0; i < sizeof(buffer); i++) {
    printf("%d", buffer[i]);
  }
  return 0;
}
