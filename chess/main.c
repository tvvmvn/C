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

const struct Piece pieces[32] = {
  {10, "kg", "♔", 1}, // user 1
  {11, "qn", "♕", 1},
  {12, "bs", "♗", 1},
  {13, "bs", "♗", 1},
  {14, "kn", "♘", 1},
  {15, "kn", "♘", 1},
  {16, "rk", "♖", 1},
  {17, "rk", "♖", 1},
  {18, "pn", "♙", 1},
  {19, "pn", "♙", 1},
  {20, "pn", "♙", 1},
  {21, "pn", "♙", 1},
  {22, "pn", "♙", 1},
  {23, "pn", "♙", 1},
  {24, "pn", "♙", 1},
  {25, "pn", "♙", 1},
  {30, "kg", "♚", 2}, // user 2
  {31, "qn", "♛", 2},
  {32, "bs", "♝", 2},
  {33, "bs", "♝", 2},
  {34, "kn", "♞", 2},
  {35, "kn", "♞", 2},
  {36, "rk", "♜", 2},
  {37, "rk", "♜", 2},
  {38, "pn", "♟", 2},
  {39, "pn", "♟", 2},
  {40, "pn", "♟", 2},
  {41, "pn", "♟", 2},
  {42, "pn", "♟", 2},
  {43, "pn", "♟", 2},
  {44, "pn", "♟", 2},
  {45, "pn", "♟", 2},
};

/* variables */

char _row, _col;
int row, col;
char _trow, _tcol;
int trow, tcol;
char nl;
int turn = 1;

int board[8][8] = {
  {16, 14, 12, 11, 10, 13, 15, 17}, // row 1
  // {18, 19, 20, 21, 22, 23, 24, 25},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  // {38, 39, 40, 41, 42, 43, 44, 45},
  {36, 34, 32, 31, 30, 33, 35, 37}, // row 8
};

/* functions */ // message

void get_idx(char _row, char _col, int* row, int* col) {
  if (_row == '1') *row = 0;
  if (_row == '2') *row = 1;
  if (_row == '3') *row = 2;
  if (_row == '4') *row = 3;
  if (_row == '5') *row = 4;
  if (_row == '6') *row = 5;
  if (_row == '7') *row = 6;
  if (_row == '8') *row = 7;

  if (_col == 'a') *col = 0;
  if (_col == 'b') *col = 1;
  if (_col == 'c') *col = 2;
  if (_col == 'd') *col = 3;
  if (_col == 'e') *col = 4;
  if (_col == 'f') *col = 5;
  if (_col == 'g') *col = 6;
  if (_col == 'h') *col = 7;
}

struct Piece getpiece(int id) {
  struct Piece piece;

  for (int i = 0; i < 32; i++) {
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

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
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

void printBoard() {
  printf("=================\n");

  for (int r = 7; r >= 0; r--) {
    printf("%d ", r + 1);

    for (int c = 0; c < 8; c++) {
      if (board[r][c] != 0) {
        for (int i=0; i<32; i++) {
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

  printf("  a b c d e f g h\n");
  printf("=================\n");
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
  if (strcmp(piece.name, "pn") == 0) {
    if (piece.team == 1) {
      if (row - 1 == trow && col == tcol) {
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
      if (row + 1 == trow && col == tcol) {
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

  if (strcmp(piece.name, "kn") == 0) {
    // up
    if (board[row + 1][col] == 0) {
      if (row + 2 == trow && col - 1 == tcol) {
        r = 2;
      }

      if (row + 2 == trow && col + 1 == tcol) {
        r = 2;
      }
    }

    // down
    if (board[row - 1][col] == 0) {
      if (row - 2 == trow && col - 1 == tcol) {
        r = 2;
      }

      if (row - 2 == trow && col + 1 == tcol) {
        r = 2;
      }
    }

    // left
    if (board[row][col - 1] == 0) {
      if (row - 1 == trow && col - 2 == tcol) {
        r = 2;
      }

      if (row + 1 == trow && col - 2 == tcol) {
        r = 2;
      }
    }

    // right
    if (board[row][col + 1] == 0) {
      if (row - 1 == trow && col + 2 == tcol) {
        r = 2;
      }

      if (row + 1 == trow && col + 2 == tcol) {
        r = 2;
      }
    }
  }

  if (strcmp(piece.name, "rk") == 0) {
    // up
    if (trow < row && col == tcol) {
      int tmp = 2;

      for (int r = row - 1; r > trow; r--) {
        if (board[r][col] != 0) {
          tmp = 0;
          break;
        }
      }

      r = tmp;
    }

    // down
    if (trow > row && col == tcol) {
      int tmp = 2;

      for (int r = row + 1; r < trow; r++) {
        if (board[r][col] != 0) {
          tmp = 0;
          break;
        }
      }

      r = tmp;
    }

    // left
    if (row == trow && tcol < col) {
      int tmp = 2;

      for (int c = col - 1; c > tcol; c--) {
        if (board[row][c] != 0) {
          tmp = 0;
          break;
        }
      }

      r = tmp;
    }

    // right
    if (row == trow && tcol > col) {
      int tmp = 2;

      for (int c = col + 1; c < tcol; c++) {
        if (board[row][c] != 0) {
          tmp = 0;
          break;
        }
      }

      r = tmp;
    }
  }

  if (strcmp(piece.name, "kg") == 0) {
    // up
    if (row + 1 == trow && col == tcol) r = 2;
    // down
    if (row - 1 == trow && col == tcol) r = 2;
    // left
    if (row == trow && col - 1 == tcol) r = 2;
    // right
    if (row == trow && col + 1 == tcol) r = 2;
    // tl
    if (row + 1 == trow && col - 1 == tcol) r = 2;
    // tr
    if (row + 1 == trow && col + 1 == tcol) r = 2;
    // br
    if (row - 1 == trow && col + 1 == tcol) r = 2;
    // bl
    if (row - 1 == trow && col - 1 == tcol) r = 2;
  }

  if (strcmp(piece.name, "bs") == 0) {
    if (abs(tcol - col) == abs(trow - row)) {
      // tl
      if (tcol - col < 0 && trow - row > 0) {
        int x = col - 1;
        int y = row + 1;
        int tmp = 2;

        while (x > tcol && y < trow) {
          if (board[y][x] != 0) {
            tmp = 0;
            break;
          }

          x--;
          y++;
        }

        r = tmp;
      }

      // tr
      if (tcol - col > 0 && trow - row > 0) {
        int x = col + 1;
        int y = row + 1;
        int tmp = 2;

        while (x < tcol && y < trow) {
          if (board[y][x] != 0) {
            tmp = 0;
            break;
          }

          x++;
          y++;
        }

        r = tmp;
      }

      // br
      if (tcol - col > 0 && trow - row < 0) {
        int x = col + 1;
        int y = row - 1;
        int tmp = 2;

        while (x < tcol && y > trow) {
          if (board[y][x] != 0) {
            tmp = 0;
            break;
          }

          x++;
          y--;
        }

        r = tmp;
      }

      // bl
      if (tcol - col < 0 && trow - row < 0) {
        int x = col - 1;
        int y = row - 1;
        int tmp = 2;

        while (x > tcol && y > trow) {
          if (board[y][x] != 0) {
            tmp = 0;
            break;
          }

          x--;
          y--;
        }

        r = tmp;
      }
    }
  }

  if (strcmp(piece.name, "qn") == 0) {
    r = 2;
  }

  return r;
}
