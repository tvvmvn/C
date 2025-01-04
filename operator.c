#include <stdio.h>


int main() {
  int x, y, z;
  
  x = 10;
  y = 20;
  z = 30;

  if (x && y || z) {
    printf("true");
  }
}