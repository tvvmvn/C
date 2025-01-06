#include <stdio.h>

enum Level {
  LOW = 1,
  MEDIUM,
  HIGH
};

int main() {
  enum Level lev = MEDIUM;

  printf("%d\n", lev);
   
  return 0;
}

// > Medium level