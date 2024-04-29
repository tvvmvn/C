#include <stdio.h>
#include <stdlib.h>


int main() {
  int *gen;

  // malloc(size)
  gen = malloc(3 * sizeof(*gen));

  gen[0] = 10;
  gen[1] = 20;
  gen[2] = 30;

  for (int i = 0; i < 3; i++)
    printf("%d ", gen[i]); // 10 20 30
}