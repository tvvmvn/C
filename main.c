#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void prt(char input[2]) {
  printf("► %s\n", input);
}

int main() {
  char input[2];
  int i = 0;

  while (1) {
    printf("%d. type some text.\n", ++i);
    
    scanf("%s", input);

    prt(input);
  }
}