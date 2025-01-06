#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

// Функция для преобразования строки в нижний регистр
void *s21_to_lower(const char *str) {
    char *result = s21_NULL; // Указатель на результат
    if (str != s21_NULL) {   // Проверка на NULL
        // Ищем длину строки, включая все символы до конца
        s21_size_t len = 0;
        while (1) {
            if (str[len] == '\0') { // Обрабатываем каждый символ, включая нулевой
                len++;
                if (str[len] == '\0') { // Двойной \0 означает конец строки
                    break;
                }
            } else {
                len++;
            }
        }

        // Выделяем память для новой строки
        result = (char *)malloc(len * sizeof(char));
        if (result != s21_NULL) { // Проверяем, выделилась ли память
            for (s21_size_t i = 0; i < len; i++) { // Преобразуем строку
                if (str[i] >= 'A' && str[i] <= 'Z') { // Заглавные буквы
                    result[i] = str[i] - 'A' + 'a';  // Преобразование
                } else {
                    result[i] = str[i]; // Копируем остальные символы
                }
            }
        }
    }
    return result; // Возвращаем указатель на результат
}