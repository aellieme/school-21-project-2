//Разбивает строку str на ряд токенов, разделенных delim.

#include <stdio.h>
#define s21_NULL (void *)0

// Глобальная переменная для хранения текущей позиции в строке
char *next_token = s21_NULL;

// Функция для вычисления длины строки
int s21_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Функция для пропуска начальных разделителей
char *s21_strspn(char *str, const char *delim) {
    int i = 0;
    while (str[i] != '\0') {
        int j = 0;
        while (delim[j] != '\0') {
            if (str[i] == delim[j]) {
                break;
            }
            j++;
        }
        if (delim[j] == '\0') {
            break;
        }
        i++;
    }
    return str + i;
}

// Функция для нахождения первого вхождения любого символа из delim в str
char *s21_strcspn(char *str, const char *delim) {
    int i = 0;
    while (str[i] != '\0') {
        int j = 0;
        while (delim[j] != '\0') {
            if (str[i] == delim[j]) {
                return str + i;
            }
            j++;
        }
        i++;
    }
    return str + i;
}

// Функция s21_strtok разбивает строку str на токены, разделенные символами из delim
char *s21_strtok(char *str, const char *delim) {
    // Если str равен NULL, продолжаем разбиение с предыдущей позиции
    if (str == s21_NULL) {
        str = next_token;
        // Если next_token равен NULL, значит, строка закончилась, возвращаем NULL
        if (str == s21_NULL) {
            return s21_NULL;
        }
    }

    // Пропускаем начальные разделители
    str = s21_strspn(str, delim);

    // Если строка закончилась, возвращаем NULL
    if (*str == '\0') {
        next_token = s21_NULL;
        return s21_NULL;
    }

    // Находим конец текущего токена
    char *token_end = s21_strcspn(str, delim);

    // Если конец строки, устанавливаем next_token в NULL
    if (*token_end == '\0') {
        next_token = s21_NULL;
    } else {
        // Иначе, ставим нулевой символ в конце токена и запоминаем следующую позицию
        *token_end = '\0';
        next_token = token_end + 1;
    }

    // Возвращаем указатель на начало текущего токена
    return str;
}

int main() {
    // Исходная строка для разбиения на токены
    char str[] = "I like my home, it is a place to be happy, have fun!";
    // Строка с разделителями
    const char delim[] = " ,!";
    
    // Получаем первый токен
    char *token = s21_strtok(str, delim);
    // Цикл продолжается, пока токен не станет NULL
    while (token != s21_NULL) {
        // Выводим текущий токен
        printf("Token: %s\n", token);
        // Получаем следующий токен, передавая NULL в качестве первого аргумента
        token = s21_strtok(s21_NULL, delim);
    }

    // Возвращаем 0, чтобы указать на успешное завершение программы
    return 0;
}