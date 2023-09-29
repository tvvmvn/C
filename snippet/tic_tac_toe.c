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


  while (1) {
    // print board
    printf("%c %c %c\n", arr[0], arr[1], arr[2]);
    printf("%c %c %c\n", arr[3], arr[4], arr[5]);
    printf("%c %c %c\n", arr[6], arr[7], arr[8]);
    
    while (scanf("%d", &input) != 1) { // 1 or 0
      // Tell the user that the entry was invalid
      printf("enter a valid number\n");
      /*
        Asterisk * tells scanf to read and ignore the value

        For scanf, the * indicates that the field is to be read but ignored, 
        so that e.g. scanf("%*d %d", &i) for the input "12 34" will ignore 12 
        and read 34 into the integer i.
      */
      scanf("%*s");
    }

    arr[--input] = 'O';

    // counterpart
    int r;

    while (1) {
      r = rand() % 9;  

      if (arr[r] == '#') {
        break;
      }
    }
    
    arr[r] = 'X';
  }
}