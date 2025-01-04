//Возвращает копию строки (str), преобразованной в верхний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL.

#include <stdio.h>
#include <stdlib.h>


#define s21_NULL (void *)0
#define s21_size_t unsigned long long

s21_size_t s21_strlen(const char *str) {
    s21_size_t len = 0;
    if (str != s21_NULL) {
        while (str[len] != '\0') {
            len++;
        }
    }
    return len;
}

void *s21_to_upper(const char *str) {
    char *result = s21_NULL;
    if (str != s21_NULL){
    s21_size_t len = 0;  // Используем size_t для длины строки
    while (str[len] != '\0') len++;

    result = (char *)malloc((len + 1) * sizeof(char));
    if (result != s21_NULL)

    for (s21_size_t i = 0; i < len; i++) {  // Используем size_t для индекса
        if (str[i] >= 'a' && str[i] <= 'z') {  //является ли символ строчной буквой
            result[i] = str[i] - 'a' + 'A';  //из строчной в заглавную преобразуем
        } else {
            result[i] = str[i];
        }
    }
    result[len] = '\0';
    }
    return result;
}

