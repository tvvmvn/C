#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* enums */
enum Team {
  WHITE = 1,
  BLACK = 2
};

/* struct */
struct Piece {
  int id;
  char name[10];
  char symbol[4];
  enum Team team; // 1 or 2
};

/* constants */
const int CELL_CNT = 8;
const int PIECE_CNT = 32;
const struct Piece PIECES[PIECE_CNT] = {
  {10, "kg", "♔", WHITE}, // user 1
  {11, "qn", "♕", WHITE},
  {12, "bs", "♗", WHITE},
  {13, "bs", "♗", WHITE},
  {14, "kn", "♘", WHITE},
  {15, "kn", "♘", WHITE},
  {16, "rk", "♖", WHITE},
  {17, "rk", "♖", WHITE},
  {18, "pn", "♙", WHITE},
  {19, "pn", "♙", WHITE},
  {20, "pn", "♙", WHITE},
  {21, "pn", "♙", WHITE},
  {22, "pn", "♙", WHITE},
  {23, "pn", "♙", WHITE},
  {24, "pn", "♙", WHITE},
  {25, "pn", "♙", WHITE},
  {30, "kg", "♚", BLACK}, // user 2
  {31, "qn", "♛", BLACK},
  {32, "bs", "♝", BLACK},
  {33, "bs", "♝", BLACK},
  {34, "kn", "♞", BLACK},
  {35, "kn", "♞", BLACK},
  {36, "rk", "♜", BLACK},
  {37, "rk", "♜", BLACK},
  {38, "pn", "♟", BLACK},
  {39, "pn", "♟", BLACK},
  {40, "pn", "♟", BLACK},
  {41, "pn", "♟", BLACK},
  {42, "pn", "♟", BLACK},
  {43, "pn", "♟", BLACK},
  {44, "pn", "♟", BLACK},
  {45, "pn", "♟", BLACK},
};

/* variables */
char _row, _col;
int row, col;
char _trow, _tcol;
int trow, tcol;
char nl;
int turn = WHITE;
int board[CELL_CNT][CELL_CNT] = {
  {16, 14, 12, 11, 10, 13, 15, 17}, // 1
  {18, 19, 20, 21, 22, 23, 24, 25},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {38, 39, 40, 41, 42, 43, 44, 45},
  {36, 34, 32, 31, 30, 33, 35, 37}, //  8
};

/* functions */ 
void get_idx(char _row, char _col, int* row, int* col);
struct Piece getpiece(int id);
int chkend();
int chkpiece();
int chktarget();
int pawn();
int rook();
int knight();
int bishop();
int queen();
int king();

/* draw */
void printBoard();

/* run the game */
int main() {
  while (1) {  
    // choose a piece
    while (1) {
      printBoard();
      printf("message: %s. choose a piece\n", turn == BLACK ? "Black" : "White");

      // get input 
      scanf("%c%c%c", &_col, &_row, &nl);
      get_idx(_row, _col, &row, &col);

      // validate piece
      int valid = chkpiece();

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
      int r = chktarget();

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
    int end = chkend();

    if (!end) {
      turn = turn == WHITE ? BLACK : WHITE;
    } else {
      printBoard();
      printf("%s WIN!\n", turn == BLACK ? "Black" : "White");
      break;
    }
  }
}

// get index
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

// get index by id
struct Piece getpiece(int id) {
  struct Piece piece;

  for (int i = 0; i < PIECE_CNT; i++) {
    if (PIECES[i].id == id) {
      piece = PIECES[i];    
    }
  }

  return piece;
}

// check piece
int chkpiece() { 
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

// check end
int chkend() {
  int end = 1;

  for (int r = 0; r < CELL_CNT; r++) {
    for (int c = 0; c < CELL_CNT; c++) {
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

// check target
int chktarget() { 
  int pieceId = board[row][col];
  int targetId = board[trow][tcol];
  struct Piece piece = getpiece(pieceId);
  int r;

  // re-select piece
  if (targetId) {
    struct Piece target = getpiece(targetId);

    if (piece.team == target.team) {
      return 1;
    }
  }

  // validate target
  if (strcmp(piece.name, "pn") == 0) {
    r = pawn();
  }

  if (strcmp(piece.name, "rk") == 0) {
    r = rook();
  }

  if (strcmp(piece.name, "kn") == 0) {
    r = knight();
  }

  if (strcmp(piece.name, "bs") == 0) {
    r = bishop();
  }

  if (strcmp(piece.name, "kg") == 0) {
    r = king();
  }

  if (strcmp(piece.name, "qn") == 0) {
    r = queen();
  }

  return r;
}

int pawn() {
  int r = 0;
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);

  if (piece.team == 1) {
    if (row + 1 == trow && col == tcol) {
      if (board[trow][tcol] == 0) {
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
      if (board[trow][tcol] == 0) {
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

  return r;
}

int rook() {
  int r = 0;
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);

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

  return r;
}

int knight() {
  int r = 0;
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);

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

  return r;
}

int bishop() {
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);
  int r = 0;

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

  return r;
}

int king() {
  int r = 0;

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

  return r;
}

int queen() {
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);
  int r = 0;

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

  // diagonal
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

  return r;
}

void printBoard() {
  printf("=================\n");

  for (int r = 7; r >= 0; r--) {
    printf("%d ", r + 1);

    for (int c = 0; c < CELL_CNT; c++) {
      if (board[r][c] != 0) {
        for (int i = 0; i < PIECE_CNT; i++) {
          if (PIECES[i].id == board[r][c]) {
            printf("%s ", PIECES[i].symbol);
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