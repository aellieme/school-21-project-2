#include "s21_sprintf.h"

int main() {
    char buffer[1028] = {0};
    s21_sprintf(buffer, "Hello %s %d", "world", 2);
    printf("%s\n", buffer);
    // s21_sprintf(buffer, "Hello %s %d", "world", 2);
    // printf("%s\n", buffer);
    return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int j = 0;
    int i = 0;

    while (format[j] != '\0') {
        if (format[j] != '%') {
            str[i++] = format[j++];
        } else {
            j++;
            if (format[j] == 'c') specifier_c(str, &i, &j, args);
            if (format[j] == 'd') specifier_d(str, &i, &j, args);
            // if (format[j] == 'f') specifier_f();
            if (format[j] == 's') specifier_s(str, &i, &j, args);
            // if (format[j] == 'u') specifier_u();
            if (format[j] == '%') specifier_per(str, format, &i, &j);
            j++;
        }
    }

    va_end(args);

    return 0;
}

void specifier_c(char *str, int *i, int *j, va_list args) {
    char ch = (char)va_arg(args, int);
    str[(*i)++] = ch;
//    (*j)++;
}

void specifier_d(char *str, int *i, int *j, va_list args) {
    int d = va_arg(args, int);
    char number[100] = {0};
    int k = 0;

    if (d < 0) {
        str[(*i)++] = '-';
        d = -d;
//        (*j)++;
    }
    if (d == 0) {
        str[(*i)++] = '0';
//        (*j)++;
    } else {
        while (d > 0) {
            number[k++] = (d % 10) + '0';
            d = d / 10;
        }
//        (*j)++;
    }

    for (int z = k - 1; z >= 0; z--) {
        str[(*i)++] = number[z];
    }
}

// void specifier_f(char *str, int *i, int *j, va_list args);

void specifier_s(char *str, int *i, int *j, va_list args) {
    char *s = va_arg(args, char *);

    for (int k = 0; s[k] != '\0'; k++) {
        str[(*i)++] = s[k];
    }
//    (*j)++;
}

// void specifier_u(char *str, int *i, int *j, va_list args);

void specifier_per(char *str, const char *format, int *i, int *j) {
    int count_per = 1;

    while (format[*j] == '%' && format[*j + 1] == '%') {
        count_per++;
//        (*j)++;
    }

    if ((format[*j] == '%' && format[*j + 1] != '%')) {
        count_per++;
//        (*j)++;
    }

    if (count_per % 2 == 0) {
        for (int k = 1; k <= count_per / 2; k++) {
            str[(*i)++] = '%';
        }
    }
    // Прописать иначе - NULL и остановка программы
}