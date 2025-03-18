#include <stdio.h>

int main(int argc, char const *argv[]) {

  float f = 9; // will be 9.000000
  int i = 9.99; // will be 9

  float f = 5 / 2; // will be 2.000000
  float f = (float) 5 / 2; // will be 2.500000

  return 0;
}