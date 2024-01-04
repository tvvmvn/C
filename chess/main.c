#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* struct */

struct Piece {
  int id;
  char name[10];
  char symbol[4];
  int team; // 1 or 2
};

/* constants */

const struct Piece pieces[4] = {
    // id name team
  {1, "pawn", "♙", 1},
  {2, "knight", "♘", 1},
  {3, "pawn", "♟", 2},
  {4, "knight", "♞", 2},
};

/* variables */

char _row, _col;
int row, col;
char _trow, _tcol;
int trow, tcol;
char nl;
int turn = 2;

int board[4][4] = {
  {1, 0, 2, 0},
  {0, 0, 0, 0},
  {0, 0, 0, 0},
  {0, 3, 0, 4},
};

/* functions */ // message

void get_idx(char _row, char _col, int* row, int* col) {
  if (_row == '4') *row = 0;
  if (_row == '3') *row = 1;
  if (_row == '2') *row = 2;
  if (_row == '1') *row = 3;

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

int vp() { // validate piece
  int valid = 0;
  int id = board[row][col]; 

  if (id != 0) {
    struct Piece piece = getpiece(id);

    if (piece.team == turn) {
      valid = 1;
    } 
  }

  return valid;
}

int _vt() { // validate target
  int valid = 1;
  int id = board[trow][tcol];

  if (id != 0) {
    struct Piece piece = getpiece(id);

    if (piece.team == turn) {
      valid = 0;
    } 
  }

  return valid;
}

int vt();

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
  printf("=========\n");

  for (int r = 0; r < 4; r++) {
    printf("%c ", row_name[r]);

    for (int c = 0; c < 4; c++) {
      if (board[r][c] != 0) {
        for (int i=0; i<4; i++) {
          if (pieces[i].id == board[r][c]) {
            printf("%s ", pieces[i].symbol);
          }
        }
      } else {
        printf("∙ ");
      }
    }
    printf("\n");
  }

  printf("  a b c d\n");
  printf("=========\n");
}

/* run the game */

int main() {
  while (1) {  
    // choose a piece
    while (1) {
      printBoard();
      printf("message: %d turn. choose a piece\n", turn);

      // get input 
      scanf("%c%c%c", &_col, &_row, &nl);
      get_idx(_row, _col, &row, &col);

      // validate piece
      int valid = vp();

      if (valid) {
        break;
      } else {
        printf("invalid piece.\n");
      }
    }

    // choose target
    while (1) {
      printBoard();
      printf("message: [%c%c] choose target or re-select piece\n", _col, _row);

      // get input
      scanf("%c%c%c", &_tcol, &_trow, &nl);
      get_idx(_trow, _tcol, &trow, &tcol);
      
      // validate target
      int r = vt();

      if (r == 1) { // re-select piece
        _row = _trow;
        _col = _tcol;
        row = trow;
        col = tcol;
      } else if (r == 2) { // select target
        break;
      } else { // 0 (invalid)
        printf("invalid movement.\n");
      }
    }

    // movement
    int temp = board[row][col];
    board[row][col] = 0;
    board[trow][tcol] = temp;
  
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

// ** validate target
int vt() { 
  int r = 0;
  int pieceId = board[row][col];
  int targetId = board[trow][tcol];

  struct Piece piece = getpiece(pieceId);

  // re-select piece
  if (targetId) {
    struct Piece target = getpiece(targetId);

    if (piece.team == target.team) {
      return 1;
    }
  }

  // validate target
  if (strcmp(piece.name, "pawn") == 0) {
    if (piece.team == 1) {
      if (row + 1 == trow && col == tcol) {
        if (targetId == 0) {
          r = 2;
        }
      }

      if (row + 1 == trow && col - 1 == tcol) {
        r = 2;
      }

      if (row + 1 == trow && col + 1 == tcol) {
        r = 2;
      }
    } else {
      if (row - 1 == trow && col == tcol) {
        if (targetId == 0) {
          r = 2;
        }
      }

      if (row - 1 == trow && col - 1 == tcol) {
        r = 2;
      }

      if (row - 1 == trow && col + 1 == tcol) {
        r = 2;
      }
    }
  }

  if (strcmp(piece.name, "knight") == 0) {
    r = 2;
  }

  return r;
}
