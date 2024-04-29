#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* 
variable scope

1 global variable
2 local variable
*/


/* 
global variable

not declared in any function or block
accessible from anywhere in codes
*/


int year = 2024; 

int main() {
  printf("%d\n", year) ;
  // 2024
}


/*
local variable

declared in function or block
not accessible from outside
*/


int main() {
  {
    int year = 2024;
  }

  printf("%d\n", year); 
  // error
}