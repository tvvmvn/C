#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char str[] = "123456789";
int win = 0;
int count = 0;

int bingo() {
  if (str[3] == str[4] && str[4] && str[5]) {
    return 1;  
  } 
  if (str[1] == str[4] && str[4] == str[7]) {
    return 1;
  }
  if (str[2] == str[4] && str[4] == str[6]) {
    return 1;
  }
  if (str[0] == str[4] && str[4] == str[8]) {
    return 1;
  }
  if (str[0] == str[3] && str[3] == str[6]) {
    return 1;
  }
  if (str[0] == str[1] && str[1] == str[2]) {
    return 1;
  }
  if (str[2] == str[5] && str[5] == str[8]) {
    return 1;
  }
  if (str[6] == str[7] && str[7] == str[8]) {
    return 1;
  }
  return 0;
}

int main() {
  int n;
  int _n;
  int com;

  srand(time(NULL));   

  while (1) {
    // Board
    printf("* TIC TAC TOE *\n");
    printf("%c %c %c\n", str[0], str[1], str[2]);
    printf("%c %c %c\n", str[3], str[4], str[5]);
    printf("%c %c %c\n", str[6], str[7], str[8]);
    printf("-\n");

    if (win == 1) {
      printf("YOU WIN!\n");
      break;
    }

    if (win == 2) {
      printf("YOU LOSE\n");
      break;
    }

    if (count > 8) {
      printf("DRAWN\n");
      break;
    }

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

    if (bingo()) {
      win = 1;
    }

    count++;

    // COM
    while(bingo() != 1) {
      com = rand() % 9;  

      if (str[com] != 'O' && str[com] != 'X') {
        str[com] = 'X';
        break;
      } 
    }

    if (win == 0 && bingo()) {
      win = 2;
    }

    count++;
  }
}