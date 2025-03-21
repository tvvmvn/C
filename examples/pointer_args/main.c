#include <stdio.h>

void f(int* p) {
  *p += 1;
}

int main(int argc, char const *argv[]) {

  int n = 1;

  f(&n); // update n

  printf("%d\n", n);

  return 0;
}
