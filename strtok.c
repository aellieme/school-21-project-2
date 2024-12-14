//Разбивает строку str на ряд токенов, разделенных delim.

#include <stdio.h>
#define s21_NULL (void *)0
#define s21_size_t unsigned long long

// Функция для вычисления длины строки
s21_size_t s21_strlen(const char *string) {
    s21_size_t i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

// Функция для нахождения первого вхождения любого символа из delim в строку str
char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = s21_NULL;
    int found = 0;

    for (int count = 0; *str1 != '\0'; str1++) {
        for (const char *ptr = str2; *ptr != '\0' && !found; ptr++) {
            if (*str1 == *ptr) {
                result = (char *)str1;
                found = 1;
            }
        }
        count++;
    }

    return result;
}

// Функция для нахождения длины начального сегмента строки str, состоящего только из символов, не входящих в delim
s21_size_t s21_strcspn(const char *str, const char *delim) {
    s21_size_t len = 0;
    while (str[len] != '\0') {
        const char *d = delim;
        while (*d != '\0') {
            if (str[len] == *d) {
                return len;
            }
            d++;
        }
        len++;
    }
    return len;
}

// Функция для нахождения длины начального сегмента строки str, состоящего только из символов, входящих в delim
s21_size_t s21_strspn(const char *str, const char *delim) {
    s21_size_t len = 0;
    while (str[len] != '\0') {
        const char *d = delim;
        while (*d != '\0') {
            if (str[len] == *d) {
                break;
            }
            d++;
        }
        if (*d == '\0') {
            break;
        }
        len++;
    }
    return len;
}

// Основная функция для разбиения строки на токены
char *s21_strtok(char *str, const char *delim) {
    // Статическая локальная переменная для хранения следующей позиции токена
    static char *next_token = s21_NULL;

    // Если str равен NULL, продолжаем разбиение с предыдущей позиции
    if (str == s21_NULL) {
        str = next_token;
        // Если next_token равен NULL, значит, строка закончилась, возвращаем NULL
        if (str == s21_NULL) {
            return s21_NULL;
        }
    }

    // Пропускаем начальные разделители
    str += s21_strspn(str, delim);

    // Если строка закончилась, возвращаем NULL
    if (*str == '\0') {
        next_token = s21_NULL;
        return s21_NULL;
    }

    // Находим конец текущего токена
    char *token_end = s21_strpbrk(str, delim);

    // Если конец строки, устанавливаем next_token в NULL
    if (token_end == s21_NULL) {
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
    char str[] = "Hello, world! This is a test.";
    const char delim[] = " ,!";

    char *token = s21_strtok(str, delim);
    while (token != s21_NULL) {
        printf("%s\n", token);
        token = s21_strtok(s21_NULL, delim);
    }

    return 0;
}