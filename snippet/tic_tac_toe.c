#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char str[] = "#########";

int isover() {
  int over = 1;

  for (int i=0; i<9; i++) {
    if (str[i] == '#') {
      over = 0;
    } 
  }

  return over;
};

int bingo() {
  // inside
  str[0] == str[1] && str[1] == str[2];
  str[0] == str[1] && str[1] == str[2];
  str[0] == str[1] && str[1] == str[2];
  str[0] == str[1] && str[1] == str[2];

  // outside
  str[0] == str[1] && str[1] == str[2];
  str[2] == str[5] && str[5] == str[8];
  str[6] == str[7] && str[7] == str[8];
  str[0] == str[3] && str[3] == str[6];
}

int main() {
  int n;
  int _n;
  int com;

  // Initialization, should only be called once.
  // Returns a pseudo-random integer between 0 and RAND_MAX.
  srand(time(NULL));   

  while (1) {
    // Board
    printf("---\n");
    printf("%c %c %c\n", str[0], str[1], str[2]);
    printf("%c %c %c\n", str[3], str[4], str[5]);
    printf("%c %c %c\n", str[6], str[7], str[8]);
    printf("---\n");

    // User
    while(1) {
      printf("choose a number between 1 - 9\n");
      scanf("%d", &n);

      _n = n - 1;

      if (str[_n] != 'O' && str[_n] != 'X') {
        str[_n] = 'O';
        break;
      } else {
        printf("occupied\n");
      }
    }

    if (isover()) {
      printf("GAME OVER\n");
      break;
    };

    // COM
    while(1) {
      com = rand() % 9;  

      if (str[com] != 'O' && str[com] != 'X') {
        str[com] = 'X';
        break;
      } 
    }

    if (isover()) {
      printf("GAME OVER\n");
      break;
    };
  }
}