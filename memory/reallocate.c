#include <stdio.h>
#include <stdlib.h>

int main() {
  int* p;
  int size;

  // allocate
  size = sizeof(*p);
  p = malloc(size);

  printf("%p is capable of %d byte(s)\n", p, size);

  // reallocate
  size = 3 * sizeof(*p);
  p = realloc(p, size);

  printf("%p is now capable of %d byte(s)\n", p, size);
}