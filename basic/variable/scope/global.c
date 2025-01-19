#include <stdio.h>

int x = 2;

void f() {
  printf("%d\n", x);
}

int main(int argc, char const *argv[])
{

  // error
  printf("%d", x);

  /* code */
  return 0;
}
