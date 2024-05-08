#include <stdio.h>
#include <stdlib.h>

/*
A static variable preserves its previous value in its previous scope 
and is not initialized again in the new scope. 

A static int variable remains in memory while the program is running. 
A normal or auto variable is destroyed when a function call 
where the variable was declared is over. 
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