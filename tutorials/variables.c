#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* 
  variable 

  1 scope
*/


/* scope */

int main() {

  if (1) {
    // variables has block scope
    int year = 2024; 
  }

  printf("%d\n", year) // error
}