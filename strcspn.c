// Вычисляет длину (префикса строки) / (подстроки) str1, который состоит исключительно из символов 
// которых нет в str2

#include <stdio.h>
#include <string.h> //только для теста!!!!!!!!!!!!!!!!!

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

s21_size_t s21_strcspn(const char *str1, const char *str2){

    s21_size_t i = 0;
    s21_size_t j;
    int found = 0;

    while (str1[i] != '\0' && !found) {
        for (j=0 ; str2[j]!='\0' && !found; j++){
            if (str1[i] == str2[j]) found = 1;            
        }
        if (!found) i++;
    }
    return i;
}


int main(){
  const char *str1 = "hello world";
  const char *str2 = "bacgv";

  //оригинал 
  size_t original_result = strcspn(str1, str2);
  printf("Original strcspn : %zu\n", original_result);

  // s21_strcspn
  s21_size_t custom_result = s21_strcspn(str1, str2);
  printf("s21_strcspn : %llu\n", custom_result);

  if (original_result == custom_result) {
    printf("match\n");
  } else {
    printf("no match\n");
  }

  return 0;
}

