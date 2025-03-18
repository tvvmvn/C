#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  
  char* s = "hello world";

  // both are same, 0x100000f94
  printf("%p\n", s); // value of pointer s
  printf("%p\n", &(s[0])); // get address of space storing 'h'
  
  return 0;
}
