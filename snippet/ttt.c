#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

enum Player { USER = 1, COM };
enum Symbol { O = 'O', X = 'X' };

char board[] = "123456789";
char start;
int n;
int _n;
int turn;
int com_idx;
int count = 0;
int bingo;
int winner;

void cmp(char a, char b, char c) {
  if (a == b && b == c) {
    bingo = a;
  }
}

void chkbingo() {
  cmp(board[3], board[4], board[5]);
  cmp(board[1], board[4], board[7]);
  cmp(board[2], board[4], board[6]);
  cmp(board[0], board[4], board[8]);
  cmp(board[0], board[3], board[6]);
  cmp(board[0], board[1], board[2]);
  cmp(board[2], board[5], board[8]);
  cmp(board[6], board[7], board[8]);
}

void drawboard() {
  printf("-----\n");
  printf("%c %c %c\n", board[0], board[1], board[2]);
  printf("%c %c %c\n", board[3], board[4], board[5]);
  printf("%c %c %c\n", board[6], board[7], board[8]);
  printf("-----\n");
};

int main() {
  srand(time(NULL));


  // START
  printf("Press any key to start game\n");

  scanf("%c", &start);

  turn = (rand() % 2) + 1;

  if (turn == 1) {
    printf("COM first\n");
  } else {
    printf("YOU first\n");
  }
  

  // PLAYING
  while (1) {    
    turn = (turn == USER) ? COM : USER;

    if (turn == USER) {
      while (1) { 
        printf("Choose a number from 1 to 9\n");
        drawboard(); 
        
        scanf("%d", &n);

        _n = n - 1;

        if (board[_n] != O && board[_n] != X) {
          board[_n] = O;
          count++;
          break;
        } else {
          printf("Occupied. try again\n");
        }
      }
    } 
    
    if (turn == COM) {
      while (1) { 
        com_idx = rand() % 9;

        if (board[com_idx] != O && board[com_idx] != X) {
          board[com_idx] = X;
          count++;
          break;
        } 
      }
    }

    chkbingo();

    if (bingo == O) {
      winner = USER;
      break;
    }
    
    if (bingo == X) { 
      winner = COM;
      break;
    } 

    if (count > 8) {
      break;
    }
  }


  // END
  if (winner == USER) {
    printf("YOU WIN\n");
  } else if (winner == COM) {
    printf("YOU LOSE\n");
  } else {
    printf("DRAW!\n");
  }

  drawboard();
 }


