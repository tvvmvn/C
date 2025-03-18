#include <stdio.h>

int main(int argc, char const *argv[]) {

  char c;
  int i;
  float f;
  double d;

  printf("%lu\n", sizeof(c)); // 1
  printf("%lu\n", sizeof(i)); // 4
  printf("%lu\n", sizeof(f)); // 4
  printf("%lu\n", sizeof(d)); // 8

  return 0;
}
