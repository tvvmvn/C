#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void f(int* adr1, int* adr2) {
  *adr1 = 1;
  *adr2 = 2;
}

int main() {
  int x, y;

  f(&x, &y);

  printf("%d %d\n", x, y);
}