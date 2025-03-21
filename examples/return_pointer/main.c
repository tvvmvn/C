#include <stdio.h>
#include <stdlib.h>

int* f() {
  int* ptr = malloc(sizeof(*ptr));

  *ptr = 2;

  return ptr;
}

int main(int argc, char const *argv[]) {

  int* ptr = f();

  printf("%d\n", *ptr);

  return 0;
}


