#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* enums */
enum Team {
  WHITE = 1,
  BLACK
};

enum Pieces {
  KING,
  QUEEN,
  BISHOP,
  KNIGHT,
  ROOK,
  PAWN
};

/* struct */
struct Piece {
  int id;
  enum Pieces name;
  char symbol[4];
  enum Team team; // 1 or 2
};

/* constants */
const int CELL_CNT = 8;
const int PIECE_CNT = 32;
const struct Piece PIECES[PIECE_CNT] = {
  {10, KING, "♔", WHITE}, // user 1
  {11, QUEEN, "♕", WHITE},
  {12, BISHOP, "♗", WHITE},
  {13, BISHOP, "♗", WHITE},
  {14, KNIGHT, "♘", WHITE},
  {15, KNIGHT, "♘", WHITE},
  {16, ROOK, "♖", WHITE},
  {17, ROOK, "♖", WHITE},
  {18, PAWN, "♙", WHITE},
  {19, PAWN, "♙", WHITE},
  {20, PAWN, "♙", WHITE},
  {21, PAWN, "♙", WHITE},
  {22, PAWN, "♙", WHITE},
  {23, PAWN, "♙", WHITE},
  {24, PAWN, "♙", WHITE},
  {25, PAWN, "♙", WHITE},
  {30, KING, "♚", BLACK}, // user 2
  {31, QUEEN, "♛", BLACK},
  {32, BISHOP, "♝", BLACK},
  {33, BISHOP, "♝", BLACK},
  {34, KNIGHT, "♞", BLACK},
  {35, KNIGHT, "♞", BLACK},
  {36, ROOK, "♜", BLACK},
  {37, ROOK, "♜", BLACK},
  {38, PAWN, "♟", BLACK},
  {39, PAWN, "♟", BLACK},
  {40, PAWN, "♟", BLACK},
  {41, PAWN, "♟", BLACK},
  {42, PAWN, "♟", BLACK},
  {43, PAWN, "♟", BLACK},
  {44, PAWN, "♟", BLACK},
  {45, PAWN, "♟", BLACK},
};

/* variables */
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
char _row, _col;
int row, col;
char _trow, _tcol;
int trow, tcol;
char nl;
int turn = WHITE;

/* functions */ 
void get_idx(char, char, int*, int*);
struct Piece getpiece(int);
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

// get piece by id
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
  if (piece.name == PAWN) {
    r = pawn();
  }

  if (piece.name == ROOK) {
    r = rook();
  }

  if (piece.name == KNIGHT) {
    r = knight();
  }

  if (piece.name == BISHOP) {
    r = bishop();
  }

  if (piece.name == KING) {
    r = king();
  }

  if (piece.name == QUEEN) {
    r = queen();
  }

  return r;
}

int pawn() {
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);
  int r = 0;

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

  return r;
}

int knight() {
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);
  int r = 0;

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

// draw board
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