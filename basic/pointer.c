#include <stdio.h>

int main() {
  int myAge = 43;  
  int* ptr = &myAge;  // pointer

  printf("%d\n", myAge); // 43
  printf("%p\n", ptr); // 0x7ffe5367e044
  printf("%d\n", *ptr); // 43

  return 0;
}