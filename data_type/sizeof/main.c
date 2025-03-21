#include <stdio.h>

int main(int argc, char const *argv[]) {

  // args: data type or variables

  printf("%lu\n", sizeof(char)); // 1
  printf("%lu\n", sizeof(int)); // 4
  printf("%lu\n", sizeof(float)); // 4
  printf("%lu\n", sizeof(double)); // 8

  return 0;
}
