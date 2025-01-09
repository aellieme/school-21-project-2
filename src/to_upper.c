//Возвращает копию строки (str), преобразованной в верхний регистр.
// В случае какой-либо ошибки следует вернуть значение NULL.


#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

void *s21_to_upper(const char *str) {
    char *result = s21_NULL;

    if (str != s21_NULL) {
        // Подсчет длины строки
        s21_size_t len = 0;
        while (str[len] != '\0') {
            len++;
        }

        // Выделение памяти для результата
        char *temp = (char *)malloc((len + 1) * sizeof(char));
        if (temp != s21_NULL) {
            // Преобразование строки
            for (s21_size_t i = 0; i < len; i++) {
                if (str[i] >= 'a' && str[i] <= 'z') {
                    temp[i] = str[i] - 'a' + 'A';
                } else {
                    temp[i] = str[i];
                }
            }
            temp[len] = '\0'; // Завершающий нулевой символ
            result = temp; // Устанавливаем результат
        }
    }
    return result; // Один общий return
}