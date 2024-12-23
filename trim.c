//Возвращает новую строку, в которой удаляются все начальные и конечные вхождения 
//набора заданных символов (trim_chars) из данной строки (src).

#include <stdlib.h>
#include <stdio.h>
#define s21_NULL (void *)0
#define s21_size_t unsigned long long


// Функция для вычисления длины строки

s21_size_t s21_strlen(const char *string){
    s21_size_t i=0;
    while (string[i]!='\0'){
        i++;
    }
    return i;
}

// Функция для удаления начальных и конечных символов из строки
void *s21_trim(const char *src, const char *trim_chars) {
        char *result = s21_NULL;

    if (src != s21_NULL || trim_chars != s21_NULL){

    if (src != s21_NULL || trim_chars != s21_NULL) {
        s21_size_t src_len = s21_strlen(src);
        s21_size_t trim_len = s21_strlen(trim_chars);
        s21_size_t start_index = 0;
        s21_size_t end_index = src_len - 1;
        int found = 0;
        int continue_search = 1;
        
        while (start_index < src_len && continue_search) {
            found = 0;
            for (s21_size_t i = 0; i < trim_len && !found; i++) {
                if (src[start_index] == trim_chars[i]) {
                    found = 1;
                }
            }
            if (!found) {
                continue_search = 0;
            } else {
                start_index++;
            }
        }
        
        continue_search = 1;
        while (end_index > start_index && continue_search) {
            found = 0;
            for (s21_size_t i = 0; i < trim_len && !found; i++) {
                if (src[end_index] == trim_chars[i]) {
                    found = 1;
                }
            }
            if (!found) {
                continue_search = 0;
            } else {
                end_index--;
            }
        }
        
        s21_size_t result_len = end_index - start_index + 1;
        result = (char *)malloc((result_len + 1) * sizeof(char));
        
        if (result != s21_NULL) {
            for (s21_size_t i = 0; i < result_len; i++) {
                result[i] = src[start_index + i];
            }
            result[result_len] = '\0';
        }
    }
    }
    
    return result;
}

int main() {
    const char *src = "   Hello, peace, sun, sea!   ";
    const char *trim_chars = " ";

    char *output = (char *)s21_trim(src, trim_chars);

    if (output != s21_NULL) {
        printf("Before: \"%s\"\n", src);
        printf("After: \"%s\"\n", output);

        free(output);
    } else {
        printf("Error\n");
    }

    return 0;
}