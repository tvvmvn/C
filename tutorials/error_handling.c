#include <errno.h>

/*
  Although C does not provide direct support 
  to error handling (or exception handling), 
  there are ways through 
  which error handling can be done in C.

  Below is a list of a few different errno values 
  and their corresponding meaning:
*/

int main() {
  int age = 15;

  printf("Guinness, please\n");

  if (age < 18) {
    printf("No kids\n");
    return 0;
  }

  printf("OK\n");
}