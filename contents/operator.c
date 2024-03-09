#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*
  C Operator

  1 Arithmatic Operator
  2 Assignment Operator
  3 Comparison Operator
  4 Logical Operator
  5 Sizeof Operator
*/


/*
  Arithmetic Operator

  1 4 Rules operator
  2 Modulus operator
  3 Increment operator
  4 Decrement operator
*/


// 4 rules operator
int main() {
  printf("%d\n", 1 + 2);
  printf("%d\n", 1 - 2);
  printf("%d\n", 1 * 2);
  printf("%d\n", 1 / 2);
}

// 2 Modulus operator

int main() {
  // dividend % divisor
  printf("%d\n", 5 % 2);
}

// 3 Increament operator
// it increases variable by 1

int main() {
  int x = 1;

  x++;

  printf("%d", x);
  // > 2
}

// 4 Decreament operator
// it decreases variable by 1

int main() {
  int x = 1;

  x--;

  printf("%d", x);
  // > 0
}


/*
  Assignment Operator

  1 variables assignment operator
  2 addition and others assignment operator  
  ...
  4 bitwise assignment operator
  &= \= ^= >>= <<=
*/


// 1 variables assignment operator
int main() {
  int n = 1;
}

// 2 addition and others assignment operator
// +=, -=, *=, /=, %=
int main() {
  int n = 1;

  n += 1; // n = n + 1
}


/*
  Comparison Operator

  1 equal operator
  2 not equal operator
  3 gt (greater than)
  4 gte (greater than or equal to) 
  5 lt (less than)
  6 lte (less than or equal to)
*/


int main() {
  // equal, not equal operator
  printf("%d\n", 0 == NULL); // 1
  printf("%d\n", 0 == false); // 1
  printf("%d\n", NULL == false); // 1
  printf("%d\n", 0 != NULL); // 0
  // gt operator
  printf("%d\n", 1 > 0);
}


/*
  Logical Operator

  1 AND
  &&

  2 OR
  |

  3 NOT
  !
*/


int main() {
  printf("%d\n", !0); // 1
}


/*
  sizeof
*/


int main() {
  char _char;
  int _int;
  float _float;
  double _double;

  /*
  Note that we use the %lu format specifer to print the result, instead of %d. 
  It is because the compiler expects the sizeof operator 
  to return a long unsigned int (%lu), instead of int (%d). 
  On some computers it might work with %d, 
  but it is safer to use %lu.
  */

  printf("%lu\n", sizeof(_char));
  // > 1 (bytes)
  printf("%lu\n", sizeof(_int));
  // > 4 (bytes)
  printf("%lu\n", sizeof(_float));
  // > 4 (bytes)
  printf("%lu\n", sizeof(_double));
  // > 8 (bytes)
}