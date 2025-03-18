#include <stdio.h>

int main() {

  int n = 2;  

  printf("%p\n", &n); // 0x7ff7bfeff288
  printf("%d\n", *(&n)); // 2

  return 0;
}