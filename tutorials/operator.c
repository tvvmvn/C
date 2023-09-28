/*
  C Operator

  1 Arithmetic Operator
  2 Assignment Operator
  3 Comparison Operator
  4 Logical Operator
  5 Sizeof Operator
*/


/*
  Arithmetic Operator

  1 4 Rules
  + - * /

  2 Modulus
  %

  3 Increment
  ++

  4 Decrement
  --
*/

int main() {
  int x = 1;

  printf("%d", ++x);
  // > 2
}

/*
  Assignment Operator

  1 assignment operator
  =
  
  2 4 rules assignment operator
  +=, -=, *=, /=
  
  3 modulus assignment operator
  %=
  
  4 bitwise assignment operator
  &= \= ^= >>= <<=
*/


/*
  Comparison Operator

  1 equal operator
  ==
  
  2 not equal operator
  !=

  3 gt (greater than)
  >

  4 lt (less than)
  <

  5 greater than or equal to
  >=

  6 less than or equal to
  <=
*/


/*
  Logical Operator

  1 AND
  &&

  2 OR
  |

  3 NOT
  !
*/


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