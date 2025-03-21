
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  // define int as fuck (alias)
  typedef int fuck;

  fuck i = 2;

  printf("%d\n", i);

  return 0;
}

