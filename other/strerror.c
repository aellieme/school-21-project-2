// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив

#include "strerror.h"


char *s21_strerror(int errnum){
  char res[512] = {'\0'};

  if (errnum <= MIN_ERRLIST || errnum >= MAX_ERRLIST) {
    s21_sprintf(res, "Unknown error: %d", errnum);
  } else {
    s21_strcpy(res, ((char *)error_list[errnum]));
  }

  return *res;
}
int main(){
  return 0;
}
