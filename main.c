#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct S {
  int id;
};

struct S ls[] = {{1}, {2}, {3}};

struct S* f(int id) {
  for (int i = 0; i < 3; i++) {
    if (ls[i].id == id) {
      return &ls[i];
    }
  } 

  // NULL pointer: pointer does not point to anything!
  return NULL;
};

int main() {
  struct S *s = f(1);

  if (s != NULL) {
    printf("%d\n", s->id);
  } else {
    printf("no piece: %p\n", s);
  }
}