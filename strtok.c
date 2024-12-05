

#include <stdio.h>
#include <string.h>
#define s21_NULL (void *)0

// Глобальная переменная для хранения текущей позиции в строке
char *next_token = s21_NULL;

char *s21_strtok(char *str, const char *delim) {
    // Если str равен NULL, продолжаем разбиение с предыдущей позиции
    if (str == s21_NULL) {
        str = next_token;
        if (str == s21_NULL) {
            return s21_NULL;
        }
    }

    // Пропускаем начальные разделители
    str += strspn(str, delim);

    // Если строка закончилась, возвращаем NULL
    if (*str == '\0') {
        next_token = s21_NULL;
        return s21_NULL;
    }

    // Находим конец текущего токена
    char *token_end = str + strcspn(str, delim);

    // Если конец строки, устанавливаем next_token в NULL
    if (*token_end == '\0') {
        next_token = s21_NULL;
    } else {
        // Иначе, ставим нулевой символ в конце токена и запоминаем следующую позицию
        *token_end = '\0';
        next_token = token_end + 1;
    }

    return str;
}

int main() {
    char str[] = "I like my home, it is a place to be happy, have fun!";
    const char delim[] = " ,!";
    

    char *token = s21_strtok(str, delim);
    while (token != s21_NULL) {
        printf("Token: %s\n", token);
        token = s21_strtok(s21_NULL, delim);
    }

    return 0;
}