#include <stdio.h>

enum Level {
  LOW = 1,
  MEDIUM,
  HIGH
};

int main() {
  enum Level lev = MEDIUM;
  
  switch (lev) {
    case 1:
      printf("Low Level");
      break;

    case 2:
      printf("Medium level");
      break;

    case 3:
      printf("High level");
      break;
  }
   
  return 0;
}

// > Medium level