#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

s21_size_t s21_strlen(const char *string){
    s21_size_t i=0;
    while (string[i]!='\0'){
        i++;
    }
    return i;
}

// int main() {
//   char str[] = "Hello, world!";
//   s21_size_t result = s21_strlen(str);
//     printf("длина строки %llu\n", result);
//   return 0;
// }
