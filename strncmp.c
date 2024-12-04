// Сравнивает не более первых n байтов str1 и str2

#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
    s21_size_t i = 0;
    s21_size_t who_more = 0;

    while ((*str1 != '\0') && (*str2 != '\0') && (*str1 == *str2) && (i<n)) {
        str1++;
        str2++;
        i++;
        }
        if (i!=n){
            if (*str1 > *str2) who_more = 1; 
            else if (*str1 < *str2) who_more = -1;
            i++;
            }
        return (i==n) ? 0 : who_more;
}



int main_s21_strncmp() {
    const char *str1 = "applepie";
    const char *str2 = "apricot";
    s21_size_t n = 5;

    int result = s21_strncmp(str1, str2, n);

    if (result == 0) {
        printf("Строки совпадают по первым %llu символам.\n", n);
    } else if (result > 0) {
        printf("Первая строка %s лексически больше второй %s тк result = %d\n", str1, str2, result);
    } else {
      printf("Первая строка %s лексически меньше второй %s тк result = %d\n",str1, str2, result);
    }

    return 0;
}
