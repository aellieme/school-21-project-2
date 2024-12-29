// Сравнивает не более первых n байтов str1 и str2

#include "strncmp.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    s21_size_t i = 0;
    s21_size_t who_more = 0;

    while (i < n && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }

    if (i < n) {
        who_more = (unsigned char)str1[i] - (unsigned char)str2[i];
    }

    return who_more;
}

int main() {
    const char *str1 = "applepie";
    const char *str2 = "apricot";
    s21_size_t n = 5;

    int result = s21_strncmp(str1, str2, n);

    if (result == 0) {
        printf("Строки совпадают по первым %llu символам.\n", n);
    } else if (result > 0) {
        printf("Первая строка %s лексически больше второй %s, разница = %d\n", str1, str2, result);
    } else {
        printf("Первая строка %s лексически меньше второй %s, разница = %d\n", str1, str2, result);
    }

    return 0;
}
