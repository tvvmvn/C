#include <stdio.h>

int main(int argc, char const *argv[]) {
  
  char* s = "hello world";

  // s is pointer
  printf("%p\n", s); // 0x100000f94  
  
  return 0;
}
