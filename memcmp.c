// Сравнивает первые n байтов str1 и str2.

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

int s21_memcmp(const void *str1, const void *str2, s21_size_t size){

    int result = 0;

    const unsigned char *byte_str1 = (const unsigned char *)str1;
    const unsigned char *byte_str2 = (const unsigned char *)str2;

    for (s21_size_t i=0; i<size && result == 0; i++){
        if (byte_str1[i] < byte_str2[i]){
            result = -1;
        } else if (byte_str1[i] > byte_str2[i]) {
          result = 1;
        }
    }
    return result;
}
int main(){
  char str1[] = "hello";
  char str2[] = "hello";
  s21_size_t size = 5;

  int comparison_result = s21_memcmp(str1, str2, size);

  if (comparison_result ==-1) {
    printf("str1 побитово меньше str2\n");
  } else if (comparison_result ==1) {
    printf("str1 побитово больше str2\n");
  } else {
    printf("str1 равна str2\n");
  }

  return 0;
}