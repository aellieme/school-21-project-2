// Выполняет поиск первого вхождения символа c(беззнаковый тип) в строке,
//     на которую указывает аргумент str. Если находит, возвращает его адрес
#include "s21_string.h"

char *s21_strchr(const char *str, unsigned int c){

  while ((*str != '\0') && (*str !=(char)c)) {  
        // Перебор до тех пор, пока не встретится c или конец строки
    ++str;
  }
  return (*str == (char)c) ? (char *)str : s21_NULL;  //*str == (char)c? если да, то (char *)str, иначе NULL
}