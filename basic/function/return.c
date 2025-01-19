#include <stdio.h>

int add(int x, int y) {
  return x + y;
}

int main(int argc, char const *argv[])
{
  int r = add(1, 2);

  printf("1 + 2 = %d\n", r);

  /* code */
  return 0;
}
