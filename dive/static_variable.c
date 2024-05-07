#include <stdio.h>
#include <stdlib.h>

/*
Static variables preserve their value even after they are out of their scope! 
Hence, a static variable preserves its previous value in its previous scope 
and is not initialized again in the new scope. 
*/

int fun() {
  static int count = 0;
  
  count++;
  
  return count;
}

int main() {
  printf("%d ", fun());
  printf("%d ", fun());
  // 1 2
  
  return 0;
}