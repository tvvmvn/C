#include <stdio.h>

int main() {

  int n = 2;  

  // pointer
  int* ptr = &n;  

  printf("%p\n", ptr); // 0x7ffe5367e044

  return 0;
}