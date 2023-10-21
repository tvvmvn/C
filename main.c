#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char board[] = "123456789";

int bingo() {
  if (board[3] == board[4] && board[4] == board[5]) {
    return 1;  
  } else if (board[1] == board[4] && board[4] == board[7]) {
    return 1;
  } else if (board[2] == board[4] && board[4] == board[6]) {
    return 1;
  } else if (board[0] == board[4] && board[4] == board[8]) {
    return 1;
  } else if (board[0] == board[3] && board[3] == board[6]) {
    return 1;
  } else if (board[0] == board[1] && board[1] == board[2]) {
    return 1;
  } else if (board[2] == board[5] && board[5] == board[8]) {
    return 1;
  } else if (board[6] == board[7] && board[7] == board[8]) {
    return 1;
  } else {
    return 0;
  }
}

void drawboard() {
  printf("---\n");
  printf("%c %c %c\n", board[0], board[1], board[2]);
  printf("%c %c %c\n", board[3], board[4], board[5]);
  printf("%c %c %c\n", board[6], board[7], board[8]);
  printf("---\n");
}

int main() {
  int n;
  int _n;
  int com;
  int win;
  int count = 0;

  srand(time(NULL));

  while (1) {
    drawboard();

    // USER
    while(1) {
      printf("choose a number between 1 - 9\n");
      scanf("%d", &n);

      _n = n - 1;

      if (board[_n] != 'O' && board[_n] != 'X') {
        board[_n] = 'O';
        count++;
        break;
      } else {
        drawboard();
        printf("occupied. try again\n");
      }
    }

    if (bingo()) {
      win = 1;
      break;
    }

    if (count > 8) {
      win = 0;
      break;
    }

    // COM
    while(1) {
      com = rand() % 9;

      if (board[com] != 'O' && board[com] != 'X') {
        board[com] = 'X';
        count++;
        break;
      } 
    }

    if (bingo()) {
      win = 2;
      break;
    }
  }

  drawboard();

  if (win == 1) {
    printf("YOU WIN\n");
  } 
  if (win == 2) {
    printf("YOU LOSE\n");
  } 
  if (win == 0) {
    printf("DRAWN\n");
  }
}