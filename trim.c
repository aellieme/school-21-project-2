#include <stdlib.h>
#include "s21_string.h"


// Функция для удаления начальных и конечных символов из строки
void *s21_trim(const char *src, const char *trim_chars) {
    char *result = s21_NULL;
    int valid_input = (src != s21_NULL && trim_chars != s21_NULL);
    
    if (valid_input) {
        s21_size_t src_len = s21_strlen(src);
        s21_size_t trim_len = s21_strlen(trim_chars);
        s21_size_t start_index = 0;
        s21_size_t end_index = src_len - 1;

        // Определяем начальный индекс
        int found = 1;
        while (start_index < src_len && found) {
            found = 0;
            for (s21_size_t i = 0; i < trim_len && !found; i++) {
                if (src[start_index] == trim_chars[i]) {
                    found = 1;
                    start_index++;
                }
            }
        }

        // Определяем конечный индекс
        found = 1;
        while (end_index > start_index && found) {
            found = 0;
            for (s21_size_t i = 0; i < trim_len && !found; i++) {
                if (src[end_index] == trim_chars[i]) {
                    found = 1;
                    end_index--;
                }
            }
        }

        // Вычисляем длину результата
        s21_size_t result_len = (end_index >= start_index) ? (end_index - start_index + 1) : 0;
        result = (char *)malloc((result_len + 1) * sizeof(char));
        
        if (result != s21_NULL) {
            // Копируем обрезанную строку в результат
            for (s21_size_t i = 0; i < result_len; i++) {
                result[i] = src[start_index + i];
            }
            result[result_len] = '\0';
        }
    }
    
    return result;
}