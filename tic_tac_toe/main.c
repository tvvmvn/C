#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

enum Player { USER = 1, COM };
enum Symbol { O = 'O', X = 'X' };

char start;
int n;
int _n;
int turn;
int com_idx;
int count = 0;
int bingo;
int winner;
char board[9];
int target = -1;

void fill_hole(int a, int b, int c) {
  if (
    board[b] != ' '
    && board[b] == board[c]
    && board[a] == ' '
  ) {
    target = a;
  } else if (
    board[a] != ' '
    && board[a] == board[c]
    && board[b] == ' '
  ) {
    target = b;
  } else if (
    board[a] != ' '
    && board[a] == board[b]
    && board[c] == ' '
  ) {
    target = c;
  }
}

void set_alg() {
  fill_hole(3, 4, 5);
  fill_hole(1, 4, 7);
  fill_hole(2, 4, 6);
  fill_hole(0, 4, 8);
  
  fill_hole(0, 3, 6);
  fill_hole(0, 1, 2);
  fill_hole(2, 5, 8);
  fill_hole(6, 7, 8);
}

void cmp(int a, int b, int c) {
  if (
    board[a] != ' '
    && board[a] == board[b] 
    && board[b] == board[c]
  ) {
    bingo = board[a];
  }
}

void chkbingo() {
  cmp(3, 4, 5);
  cmp(1, 4, 7);
  cmp(2, 4, 6);
  cmp(0, 4, 8);
  
  cmp(0, 3, 6);
  cmp(0, 1, 2);
  cmp(2, 5, 8);
  cmp(6, 7, 8);
}

void drawboard() {
  printf(" %c | %c | %c \n", board[0], board[1], board[2]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[3], board[4], board[5]);
  printf("---+---+---\n");
  printf(" %c | %c | %c \n", board[6], board[7], board[8]);
};

int main() {
  srand(time(NULL));

  for (int i=0; i<9; i++) {
    board[i] = ' ';
  }

  // START
  printf("Press any key to start game\n");

  scanf("%c", &start);

  turn = (rand() % 2) + 1;

  if (turn == 1) {
    printf("YOU first\n");
  } else {
    printf("COM first\n");
  }
  

  // PLAYING
  while (1) {    
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
      set_alg();

      if (target > -1) {
        board[target] = X;
        target = -1;
      } else {
        while (1) { 
          com_idx = rand() % 9;

          if (board[com_idx] == ' ') {
            board[com_idx] = X;
            break;
          } 
        }
      }

      count++;
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

    turn = (turn == USER) ? COM : USER;
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


