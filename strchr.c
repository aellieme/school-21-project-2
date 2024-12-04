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

int main_s21_strchr(){
  const char *string = "Hello, World!";
  char *is_found = s21_strchr(string, 'W');
  if (is_found) {
    printf("'W' найдено по адресу %p\n", is_found);
  } else {
    printf("'W' не найдено\n");
  }
  return 0;
}
