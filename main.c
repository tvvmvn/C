#include <stdio.h>
#include <stdlib.h>


char* getS() {
  char* s = "hello C!";

  printf("adr1: %p\n", s); // f83
  
  return s;
}

int main() {
  char* s = getS();

  printf("adr2: %p\n", s); // f83
  printf("%s\n", s);
}