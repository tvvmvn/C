#include <stdio.h>

int main(int argc, char const *argv[]) {

  float f1 = 5 / 2; // will be 2.000000
  float f2 = (float) 5 / 2; // will be 2.500000

  printf("%f\n", f1);
  printf("%f\n", f2);

  return 0;
}