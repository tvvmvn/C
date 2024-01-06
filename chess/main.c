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
  enum Team team; 
};

/* constants */
const int ROW_CNT = 8;
const int COL_CNT = 8;
const int PIECE_CNT = 32;
const struct Piece PIECES[PIECE_CNT] = {
  {1, KING, "♔", WHITE}, 
  {2, QUEEN, "♕", WHITE},
  {3, BISHOP, "♗", WHITE},
  {4, BISHOP, "♗", WHITE},
  {5, KNIGHT, "♘", WHITE},
  {6, KNIGHT, "♘", WHITE},
  {7, ROOK, "♖", WHITE},
  {8, ROOK, "♖", WHITE},
  {9, PAWN, "♙", WHITE},
  {10, PAWN, "♙", WHITE},
  {11, PAWN, "♙", WHITE},
  {12, PAWN, "♙", WHITE},
  {13, PAWN, "♙", WHITE},
  {14, PAWN, "♙", WHITE},
  {15, PAWN, "♙", WHITE},
  {16, PAWN, "♙", WHITE},
  {17, KING, "♚", BLACK},
  {18, QUEEN, "♛", BLACK},
  {19, BISHOP, "♝", BLACK},
  {20, BISHOP, "♝", BLACK},
  {21, KNIGHT, "♞", BLACK},
  {22, KNIGHT, "♞", BLACK},
  {23, ROOK, "♜", BLACK},
  {24, ROOK, "♜", BLACK},
  {25, PAWN, "♟", BLACK},
  {26, PAWN, "♟", BLACK},
  {27, PAWN, "♟", BLACK},
  {28, PAWN, "♟", BLACK},
  {29, PAWN, "♟", BLACK},
  {30, PAWN, "♟", BLACK},
  {31, PAWN, "♟", BLACK},
  {32, PAWN, "♟", BLACK},
};

/* variables */
int board[ROW_CNT][COL_CNT] = {
  {23, 21, 19, 18, 17, 20, 22, 24}, 
  {25, 26, 27, 28, 29, 30, 31, 32},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0},
  {9, 10, 11, 12, 13, 14, 15, 16},
  {7, 5, 9, 2, 1, 4, 6, 8}, 
};
char _row, _col;
int row, col;
char _trow, _tcol;
int trow, tcol;
char nl;
int turn = WHITE;
char msg[100];

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
    printBoard();
    printf("► %s choose a piece\n", turn == BLACK ? "Black" : "White");

    while (1) {
      // get input 
      scanf("%c%c%c", &_col, &_row, &nl);
      get_idx(_row, _col, &row, &col);

      // validate piece
      int valid = chkpiece();

      if (!valid) {
        printf("► invalid piece. try again\n");
      } else {
        break;
      }
    }

    // choose target
    printBoard();
    printf("► [%c%c] choose target or re-select piece\n", _col, _row);

    while (1) {
      // get input
      scanf("%c%c%c", &_tcol, &_trow, &nl);
      get_idx(_trow, _tcol, &trow, &tcol);
      
      // validate target
      int r = chktarget();

      if (r == 0) { 
        printf("► invalid movement. try again\n");
      } else if (r == 1) { 
        printf("► [%c%c] choose target or re-select piece\n", _tcol, _trow);
        row = trow;
        col = tcol;
      } else { // 2
        break;
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
      printf("► %s WIN!\n", turn == BLACK ? "Black" : "White");
      break;
    }
  }
}

// get index
void get_idx(char _row, char _col, int* row, int* col) {
  if (_row == '1') *row = 7;
  if (_row == '2') *row = 6;
  if (_row == '3') *row = 5;
  if (_row == '4') *row = 4;
  if (_row == '5') *row = 3;
  if (_row == '6') *row = 2;
  if (_row == '7') *row = 1;
  if (_row == '8') *row = 0;

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

  for (int r = 0; r < ROW_CNT; r++) {
    for (int c = 0; c < COL_CNT; c++) {
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
  } else {
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
  if (board[row - 1][col] == 0) {
    if (row - 2 == trow && col - 1 == tcol) {
      r = 2;
    }

    if (row - 2 == trow && col + 1 == tcol) {
      r = 2;
    }
  }

  // down
  if (board[row + 1][col] == 0) {
    if (row + 2 == trow && col - 1 == tcol) {
      r = 2;
    }

    if (row + 2 == trow && col + 1 == tcol) {
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

    // tr
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

    // br
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

    // bl
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
  }

  return r;
}

int king() {
  int r = 0;

  // up
  if (row - 1 == trow && col == tcol) r = 2;
  // down
  if (row + 1 == trow && col == tcol) r = 2;
  // left
  if (row == trow && col - 1 == tcol) r = 2;
  // right
  if (row == trow && col + 1 == tcol) r = 2;
  // tl
  if (row - 1 == trow && col - 1 == tcol) r = 2;
  // tr
  if (row - 1 == trow && col + 1 == tcol) r = 2;
  // br
  if (row + 1 == trow && col + 1 == tcol) r = 2;
  // bl
  if (row + 1 == trow && col - 1 == tcol) r = 2;

  return r;
}

int queen() {
  int pieceId = board[row][col];
  struct Piece piece = getpiece(pieceId);
  int r = 0;

  // up
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

  // down
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

    // tr
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

    // br
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

    // bl
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
  }

  return r;
}

// draw board
void printBoard() {
  printf("\n");

  for (int r = 0; r < ROW_CNT; r++) {
    printf("%d ", ROW_CNT - r);

    for (int c = 0; c < COL_CNT; c++) {
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

  printf("  a b c d e f g h\n\n");
}