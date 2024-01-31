#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct S {
  int id;
};

int main() {
  struct S list[3] = {{1}, {2}, {3}};

  struct S s = {4};
  list[2] = s;

  printf("%d\n", list[2].id); // expected 4;
}
