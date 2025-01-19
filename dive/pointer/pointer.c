#include <stdio.h>

int main() {

  int n = 2;  

  // pointer
  int* ptr = &n;  

  printf("%d\n", n); // 2
  printf("%p\n", ptr); // 0x7ffe5367e044
  printf("%d\n", *ptr); // 2

  return 0;
}