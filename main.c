#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
  char s1[20] = "Hello ";
  char s2[] = "World";

  strcat(s1, s2);

  printf("%s\n", s1); 
}