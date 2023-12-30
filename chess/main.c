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

int _row;
char _col;
int row, col;
int _row_d;
char _col_d;
int row_d, col_d;
int turn = 2;

/* functions */

void get_idx(int _row, char _col, int* row, int* col) {
  if (_row == 4) *row = 0;
  if (_row == 3) *row = 1;
  if (_row == 2) *row = 2;
  if (_row == 1) *row = 3;

  if (_col == 'a') *col = 0;
  if (_col == 'b') *col = 1;
  if (_col == 'c') *col = 2;
  if (_col == 'd') *col = 3;
}

struct Piece getpiece(int id) {
  struct Piece piece;

  for (int i = 0; i < 4; i++) {
    if (pieces[i].id == id) {
      piece = pieces[i];    
    }
  }

  return piece;
}

int vt() { // validate target
  int valid;
  int id = board[row][col]; 

  if (id == 0) {
    valid = 0;
  } else {
    struct Piece piece = getpiece(id);

    if (piece.team == turn) {
      valid = 1;
    } else { // pick enemy
      valid = 0;
    }
  }

  return valid;
}

int vd() { // validate dest
  int valid;
  int id = board[row_d][col_d];

  if (id == 0) {
    valid = 1;
  } else {
    struct Piece piece = getpiece(id);

    if (piece.team != turn) { // take enemy
      valid = 1;
    } else { // same team
      valid = 0;
    }
  }

  return valid;
}

int get_end() {
  int end = 1;

  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      int id = board[r][c];

      if (id) {
        struct Piece piece = getpiece(id);

        if (piece.team != turn) {
          end = 0;
        }
      }
    }
  }

  return end;
}

/* draw */

char row_name[] = "4321"; 

void printBoard() {
  printf("==========\n");

  for (int r = 0; r < 4; r++) {
    printf("%c ", row_name[r]);

    for (int c = 0; c < 4; c++) {
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

/* run the game */

int main() {
  while (1) {  
    // choose a piece
    while (1) {
      printBoard();
      printf("message: %d turn. pick up\n", turn);

      // get input 
      scanf("%c %d", &_col, &_row);
      get_idx(_row, _col, &row, &col);

      // validate target
      int valid = vt();

      if (valid) {
        break;
      } else {
        printf("invalid target.\n");
      }
    }

    // choose destination
    while (1) {
      printBoard();
      printf("message: choose dest\n");

      // get input
      scanf(" %c %d", &_col_d, &_row_d);
      get_idx(_row_d, _col_d, &row_d, &col_d);
      
      // validate dest
      int valid = vd();

      if (valid) {
        break;
      } else {
        printf("invalid movement.\n");
      }
    }

    // movement
    int temp = board[row][col];
    board[row][col] = 0;
    board[row_d][col_d] = temp;
  
    // get result
    int end = get_end();

    if (!end) {
      turn = turn == 1 ? 2 : 1;
    } else {
      printBoard();
      printf("%d WIN!\n", turn);
      break;
    }
  }
}