#include <stdio.h>

int main() {
  // Get sum from 1 to 10.

  int sum = 0;

  for (int i = 1; i <= 10; i++) {
    sum += i;
  }

  printf("sum from 1 to 10: %d\n", sum);
}
