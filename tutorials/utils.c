#include <stdio.h>
#include <string.h>
// math
#include <math.h>
// date and time
#include <time.h>
#include <setjmp.h>


/*
  Math
*/

int main() {
  printf("%f\n", sqrt(16));
  printf("%f\n", ceil(1.2));
  printf("%f\n", floor(1.2));
  printf("%f\n", pow(2, 7));
}

/*
  abs(x)	get the absolute value of x
  acos(x)	get the arccosine of x
  asin(x)	get the arcsine of x
  atan(x)	get the arctangent of x
  cbrt(x)	get the cube root of x
  cos(x)	get the cosine of x
  exp(x)	get the value of Ex
  sin(x)	get the sine of x (x is in radians)
  tan(x)	get the tangent of an angle
*/



static jmp_buf buf;

void second() {
  // prints
  printf("second\n"); 
  // jumps back to where setjmp was called - making setjmp now return 1
  longjmp(buf, 1);    
}

void first() {
  second();
  // does not print
  printf("first\n"); 
}

int main() {
  if (!setjmp(buf))
    // when executed, setjmp returned 0
    first();          
  // when longjmp jumps back, setjmp returns 1
  else     
    // prints           
    printf("main\n"); 

  return 0;
}
