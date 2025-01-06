//Возвращает новую строку, в которой указанная строка (str) вставлена 
//в указанную позицию (start_index) в данной строке (src). 

#include <stdio.h>
#include <stdlib.h>


#define s21_NULL (void *)0
#define s21_size_t unsigned long long


// Функция для вставки строки в указанную позицию
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
    char *result = s21_NULL;

    if (src != s21_NULL && str != s21_NULL) {
        s21_size_t src_len = 0;  // Длина исходной строки
        while (src[src_len] != '\0') src_len++;

        s21_size_t str_len = 0;  // Длина вставляемой строки
        while (str[str_len] != '\0') str_len++;

        if (start_index <= src_len) {  // Проверяем, что индекс в пределах строки
            result = (char *)malloc((src_len + str_len + 1) * sizeof(char));
            if (result != s21_NULL) {
                // Копируем часть исходной строки до start_index
                for (s21_size_t i = 0; i < start_index; i++) {
                    result[i] = src[i];
                }

                // Вставляем новую строку
                for (s21_size_t i = 0; i < str_len; i++) {
                    result[start_index + i] = str[i];
                }

                // Копируем оставшуюся часть исходной строки
                for (s21_size_t i = start_index; i < src_len; i++) {
                    result[str_len + i] = src[i];
                }

                result[src_len + str_len] = '\0';
            }
        }
    }

    return result;
}