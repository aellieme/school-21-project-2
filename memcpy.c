// Копирует n символов из src в dest.

// memory_to — указатель на область памяти, куда будут скопированы данные.
// memory_from — указатель на  область памяти, откуда будут скопированы данные.
//  size — количество байт, которые нужно скопировать.

#include <stdio.h>

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

void *s21_memcpy(void *memory_to, const void *memory_from, size_t size){

    for (size_t i=0; i<size; i++){
        ((unsigned char*)memory_to)[i] = ((unsigned char *)memory_from)[i];
    }
    return memory_to;
}

int main(){
    //test1
  char source[] = "Hello, World!";
  char destination[100];

  s21_memcpy(destination, source, sizeof(source) + 1);  // +1 для учета нулевого символа

  printf("Source: %s\n", source);
  printf("Destination: %s\n", destination);


  //test2
  int numbers_src[] = {1, 2, 3, 4, 5};
  int numbers_dest[5];

  s21_memcpy(numbers_dest, numbers_src, sizeof(numbers_src));

  printf("Numbers Source: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", numbers_src[i]);
  }
  printf("\n");

  printf("Numbers Destination: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", numbers_dest[i]);
  }

  return 0;
}