#include <stdio.h>
#include <string.h>
#include <math.h>

/*
  Loop

  1 for loop
  2 while loop
*/


/*
  while loop
*/

// sum of 1 - 10
int main() {
  int i = 1;
  int sum = 0;

  while (i<=10) {
    sum += i;
    i++;
  }

  printf("result: %d\n", sum);
}

int main() {
  int i = 1;
  int sum = 0;

  /*
    This loop will execute the code block once, 
    before checking if the condition is true
    
    The loop will always be executed at least once, 
    even if the condition is false, because the code block is executed 
    before the condition is tested:
  */
  do {
    sum += i;
    i++;
  } while (i<=10);

  printf("result: %d\n", sum);
}