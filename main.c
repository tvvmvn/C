#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int getcrds(char input[2]) {
  int crds[2] = {6, 1};

  return crds;
}

int main() {
  // expected {6, 1}
  int crds[2] = getcrds("b7"); 

  printf("crds: [%d, %d]", crds[0], crds[1]);
}