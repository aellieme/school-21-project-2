// Добавляет строку, на которую указывает str_from, в конец строки, на которую
// указывает str_to, длиной до n символов.

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

char *s21_strncat(char *str_to, const char *str_from, s21_size_t size){
    s21_size_t len = 0;
    s21_size_t i = 0;
    while (str_to[len] != '\0'){
        len ++;
    }
    for (i = 0; i < size && str_from[i]!= '\0'; i++) {
        str_to[len+i]=str_from[i];
    }
    str_to[len+i]='\0';
    return str_to;
}

int main(){
    char str1[50] = "Hello ";
    const char str2[] = "world!";
    s21_strncat(str1, str2, 4);
    printf("result: %s\n", str1);
    return 0;
}