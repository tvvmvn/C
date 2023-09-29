#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int a;
  int b;

  printf("enter two numbers to add\n");

  while (scanf("%d %d", &a, &b) < 2) {
    printf("try again\n");
    scanf("%*s");
  }

  printf("result: %d\n", a + b);
}