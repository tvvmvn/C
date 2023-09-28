#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Tic Tac Toe
int main() {

  int input;

  char arr[9] = {
    '#', '#', '#',
    '#', '#', '#',
    '#', '#', '#',
  };

  // Initialization, should only be called once.
  srand(time(NULL));   
  // Returns a pseudo-random integer between 0 and RAND_MAX.

  for (int i=0; i<9; i++) {

    printf("%c %c %c\n", arr[0], arr[1], arr[2]);
    printf("%c %c %c\n", arr[3], arr[4], arr[5]);
    printf("%c %c %c\n", arr[6], arr[7], arr[8]);

    scanf("%d", &input);

    arr[input] = 'O';

    int r = rand() % 9;     
    
    arr[r] = 'X';
  }
}