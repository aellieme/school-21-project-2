// Вычисляет длину (префикса строки) / (подстроки) str1, который состоит исключительно из символов 
// которых нет в str2

#include "s21_string.h"

s21_size_t s21_strcspn(const char *str1, const char *str2){

    s21_size_t i = 0;
    s21_size_t j;
    int found = 0;

    while (str1[i] != '\0' && !found) {
        for (j=0 ; str2[j]!='\0' && !found; j++){
            if (str1[i] == str2[j]) found = 1;            
        }
        if (!found) i++;
    }
    return i;
}