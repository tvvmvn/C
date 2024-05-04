#include <stdio.h>
#include <stdlib.h>

int gcdDivision(int a, int b) {
  while (b != 0) {
    int remainder = a % b;

    printf("%d = %d * %d + %d\n", a, a / b, b, remainder);
    
    a = b;
    b = remainder;
  }

  return a;
}

int main() {
  int a = 120;
  int b = 25;

  printf("The Euclidean algorithm using division:\n\n");
  printf("The GCD of %d and %d is: %d\n", a, b, gcdDivision(a, b));

  return 0;
}