#include <stdio.h>
#include <stdlib.h>

int main() {

  int* ptr; // points to random space

  ptr = NULL;

  printf("%p\n", ptr); // 0x0

  return 0;
}