#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* struct */

struct Piece {
  int id;
  char name;
  int team; // 1 or 2
};

/* variables */

struct Piece pieces[4] = {
    // id name team
  {1, 'p', 1},
  {2, 'k', 1},
  {3, 'P', 2},
  {4, 'K', 2},
};

int board[4][4] = {
  {1, 0, 2, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 3, 0, 4},
};

int row;
char _col;
int col;
int row_d;
char _col_d;
int col_d;
int turn = 2;
int win = 0;
int end;

/* functions */

void printBoard() {
  printf("==========\n");

  for (int r=0; r<4; r++) {
    printf("%d ", r);

    for (int c=0; c<4; c++) {
      // thare is a piece
      if (board[r][c] != 0) {
        for (int i=0; i<4; i++) {
          if (pieces[i].id == board[r][c]) {
            printf("%c ", pieces[i].name);
          }
        }
      // empty cell
      } else {
        printf("∙ ");
      }
    }
    printf("\n");
  }

  printf("  a b c d\n");
  printf("==========\n");
}

int get_col(char _col) {
  int col;

  if (_col == 'a') col = 0;
  if (_col == 'b') col = 1;
  if (_col == 'c') col = 2;
  if (_col == 'd') col = 3;

  return col;
};

int movement() {
  int r = 0;

  if (turn == 2) {
    if (row - 1 == row_d && col + 1 == col_d) {
      r = 1;
    } else if (row - 1 == row_d && col - 1 == col_d) {
      r = 1;
    }
  } else {
    if (row + 1 == row_d && col + 1 == col_d) {
      r = 1;
    } else if (row + 1 == row_d && col - 1 == col_d) {
      r = 1;
    }
  }

  return r;
}

/* run the game */

int main() {
  // PLAY
  while (1) {  

    // Choose a piece
    while (1) {
      printBoard();
      printf("message: %d turn. pick up\n", turn);

      scanf("%d %c", &row, &_col);

      col = get_col(_col);

      // validate
      if (board[row][col] == 0) {
        printf("message: empty cell. try again\n");
      } else {
        int stop = 0;

        for (int i=0; i<4; i++) {
          if (pieces[i].id == board[row][col]) {
            if (pieces[i].team == turn) {
              stop = 1;
            } else { // wrong team 
              printf("message: not your team. try again\n");
            }
          }
        }

        if (stop) {
          break;
        }
      }
    }

    // Choose a destination
    while (1) {
      printBoard();
      printf("message: choose dest\n");

      scanf("%d %c", &row_d, &_col_d);

      col_d = get_col(_col_d);
      
      int takeable = movement();

      // validate dest
      if (takeable == 0) {
        printf("message: Not takeable. try again\n");
      } else {
        int stop = 0;
        int id = board[row_d][col_d];

        if (id == 0) {
          break;
        }

        for (int i=0; i<4; i++) {
          if (pieces[i].id == id) {
            if (pieces[i].team != turn) { // take enemy
              stop = 1;
            } else {
              printf("message: already a piece. try again\n");
            }
          }
        }

        if (stop) {
          break;
        }
      }
    }

    // move
    int temp = board[row][col];
    board[row][col] = 0;
    board[row_d][col_d] = temp;

    // change turn
    turn = turn == 1 ? 2 : 1;
  
    // get result
    end = 1;

    for (int r=0; r<4; r++) {
      for (int c=0; c<4; c++) {
        int id = board[r][c];
        
        if (id) {
          for (int i=0; i<4; i++) {
            if (pieces[i].id == id) {
              if (pieces[i].team == turn) {
                end = 0;
              }
            }
          }
        }
      }
    }

    // GAME END
    if (end) {
      printBoard();
      printf("%d WIN!\n", turn);
      break;
    }
  }
}