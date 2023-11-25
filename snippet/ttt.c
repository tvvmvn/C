#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

char board[] = "123456789";
int n;
int _n;
int com;
int count = 0;
int symbol;
int win = 0;
int turn;
char start;

void cmp(char a, char b, char c) {
  if (a == b && b == c) {
    symbol = a;
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

  // start game
  printf("Press any key to start game\n");

  scanf("%c", &start);

  turn = (rand() % 2) + 1;

  if (turn == 1) {
    printf("COM first\n");
  } else {
    printf("YOU first\n");
  }
  
  // playing game
  while (1) {    
    // set turn
    turn = turn == 1 ? 2 : 1;

    // user  
    if (turn == 1) {
      while (1) { 
        printf("Choose a number from 1 to 9\n");
        drawboard(); 
        
        scanf("%d", &n);

        _n = n - 1;

        if (board[_n] != 'O' && board[_n] != 'X') {
          board[_n] = 'O';
          count++;
          break;
        } else {
          printf("Occupied. try again\n");
        }
      }
    } 
    
    // com
    if (turn == 2) {
      while (1) { 
        com = rand() % 9;

        if (board[com] != 'O' && board[com] != 'X') {
          board[com] = 'X';
          count++;
          break;
        } 
      }
    }

    // check 
    chkbingo();

    if (symbol == 'O') {
      win = 1;
      break;
    }
    
    if (symbol == 'X') { 
      win = 2;
      break;
    } 

    if (count > 8) {
      break;
    }
  }

  // game end
  if (win == 1) {
    printf("YOU WIN\n");
  } else if (win == 2) {
    printf("YOU LOSE\n");
  } else {
    printf("DRAW!\n");
  }
  drawboard();
 }


