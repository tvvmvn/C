#include <stdio.h>

int add(int x, int y) {
  printf("%d + %d = %d\n", x, y, x + y);
}

int main(int argc, char const *argv[])
{
  add(1, 2);

  /* code */
  return 0;
}
