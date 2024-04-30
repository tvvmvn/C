#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p;
  p = malloc(sizeof(*p));

  printf("%p is capable of 4 bytes\n", p);

  free(p);
  p = NULL;

  printf("%p", p);
}