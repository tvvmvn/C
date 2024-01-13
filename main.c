#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char c = 'j';
  char *p = &c;

  printf("%c\n", c); // j
  printf("%p\n", p); // 0x7ff7bfeff32f
}
