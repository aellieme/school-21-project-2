//Находит первое вхождение всей строки needle (не включая завершающий нулевой символ)
//которая появляется в строке haystack.

#include <stdio.h>
#define s21_NULL (void *)0

// Реализация функции strstr с использованием указателей
char *s21_strstr(const char *haystack, const char *needle) {
    // Проверка на пустую строку needle
    if (*needle == '\0') {
        return (char *)haystack; // Если needle пустая строка, возвращаем указатель на начало haystack
    }

    // Указатель на начало haystack
    const char *h = haystack;

    // Итерация по haystack
    while (*h != '\0') {
        // Указатель на начало needle
        const char *n = needle;

        // Указатель для сравнения с текущим символом в haystack
        const char *current = h;

        // Итерация по needle для сравнения с текущим символом в haystack
        while (*n != '\0' && *current == *n) {
            current++;
            n++;
        }

        // Если дошли до конца needle, значит подстрока найдена
        if (*n == '\0') {
            return (char *)h; // Возвращаем указатель на начало найденной подстроки
        }

        // Переходим к следующему символу в haystack
        h++;
    }

    return s21_NULL; // Подстрока не найдена
}

int main(void) {
    char haystack[] = "Marina hello";
    char *needle = s21_strstr(haystack, "ina");
    
    printf("haystack = %s\n", haystack);
    if (needle != s21_NULL) {
        printf("needle = %s\n", needle);
    } else {
        printf("no\n");
    }
    
    return 0;
}