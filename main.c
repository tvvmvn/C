#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main() {

  char msg[100];
  // you can't assign values to array
  strcpy(msg, "hello");

  printf("%d\n", strlen(msg) > 0);
}
