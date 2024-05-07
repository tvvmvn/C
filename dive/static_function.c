#include <stdio.h>
#include <stdlib.h>

/*
Unlike global functions in C, access to static functions is restricted 
to the file where they are declared. 
Therefore, when we want to restrict access to functions, 
we make them static. 

Another reason for making functions static can be the reuse 
of the same function name in other files.
*/

static void f() { 
  printf("static function is called"); 
};

int main() {
  f();
}