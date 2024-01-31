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
  enum Pieces name;
  enum Team team; 
  char symbol[4];
  int mcount; // castling, 2 move
};

/* constants */
const int ROW_CNT = 8;
const int COL_CNT = 8;
const int PIECE_CNT = 32;
struct Piece pieces[PIECE_CNT] = {
  {KING, WHITE, "♔", 0},
  {QUEEN, WHITE, "♕", 0},
  {BISHOP, WHITE, "♗", 0},
  {BISHOP, WHITE, "♗", 0},
  {KNIGHT, WHITE, "♘", 0},
  {KNIGHT, WHITE, "♘", 0},
  {ROOK, WHITE, "♖", 0},
  {ROOK, WHITE, "♖", 0},
  {PAWN, WHITE, "♙", 0},
  {PAWN, WHITE, "♙", 0},
  {PAWN, WHITE, "♙", 0},
  {PAWN, WHITE, "♙", 0},
  {PAWN, WHITE, "♙", 0},
  {PAWN, WHITE, "♙", 0},
  {PAWN, WHITE, "♙", 0},
  {PAWN, WHITE, "♙", 0},
  {KING, BLACK, "♚", 0},
  {QUEEN, BLACK, "♛", 0},
  {BISHOP, BLACK, "♝", 0},
  {BISHOP, BLACK, "♝", 0},
  {KNIGHT, BLACK, "♞", 0},
  {KNIGHT, BLACK, "♞", 0},
  {ROOK, BLACK, "♜", 0},
  {ROOK, BLACK, "♜", 0},
  {PAWN, BLACK, "♟", 0},
  {PAWN, BLACK, "♟", 0},
  {PAWN, BLACK, "♟", 0},
  {PAWN, BLACK, "♟", 0},
  {PAWN, BLACK, "♟", 0},
  {PAWN, BLACK, "♟", 0},
  {PAWN, BLACK, "♟", 0},
  {PAWN, BLACK, "♟", 0},
};

/* variables */
int board[ROW_CNT][COL_CNT] = {
  {22, 20, 18, 17, 16, 19, 21, 23}, 
  {24, 25, 26, 27, 28, 29, 30, 31},
  {-1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1},
  {-1, -1, -1, -1, -1, -1, -1, -1},
  {8, 9, 10, 11, 12, 13, 14, 15},
  {6, 4, 8, 1, 0, 3, 5, 7}, 
};
char _row, _col;
int row, col;
char _trow, _tcol;
int trow, tcol;
char nl;
int turn = WHITE;

/* functions */ 
void get_idx(char, char, int*, int*);
int chkend();
int chkpiece();
int chktarget();
int pawn();
void promotion();
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
    int id = board[row][col];
    board[row][col] = -1;
    board[trow][tcol] = id;
    
    // increase mcount 
    pieces[id].mcount++;

    // get result
    int end = chkend();

    // check promotion
    // promotion();

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
  char rows[] = "12345678";
  char cols[] = "abcdefgh";

  for (int i = 0; i < strlen(rows); i++) {
    if (_row == rows[i]) *row = (strlen(rows) - 1) - i;
  }

  for (int i = 0; i < strlen(cols); i++) {
    if (_col == cols[i]) *col = i;
  }
}

// check piece
int chkpiece() { 
  int id = board[row][col]; 
  int valid = 0;

  if (id > -1) {
    if (pieces[id].team == turn) {
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

      if (id > -1) {
        if (pieces[id].name == KING && pieces[id].team != turn) {
          end = 0;
        }
      }
    }
  }

  return end;
}

// check target
int chktarget() { 
  int id = board[row][col];
  struct Piece piece = pieces[id];
  int target = board[trow][tcol];
  int r;

  // there a piece on target
  if (target > -1) {
    struct Piece taker = pieces[target];

    if (piece.team == taker.team) {
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
  int id = board[row][col];
  struct Piece piece = pieces[id];
  int r = 0;

  if (piece.team == WHITE) {
    if (row - 1 == trow && col == tcol) {
      if (board[trow][tcol] == -1) {
        r = 2;
      }
    } 

    if (row - 1 == trow && col - 1 == tcol) {
      if (board[trow][tcol] > -1) {
        r = 2;
      }
    }

    if (row - 1 == trow && col + 1 == tcol) {
      if (board[trow][tcol] > -1) {
        r = 2;
      }
    }

    // 2 steps forward
    if (row - 2 == trow && col == tcol) {
      if (
        piece.mcount < 1
        && board[row - 1][col] == -1 
        && board[trow][tcol] == -1
      ) {
        r = 2;
      }
    }
  } 
  
  if (piece.team == BLACK) {
    if (row + 1 == trow && col == tcol) {
      if (board[trow][tcol] == -1) {
        r = 2;
      }
    }

    if (row + 1 == trow && col - 1 == tcol) {
      if (board[trow][tcol] > -1) {
        r = 2;
      }
    }

    if (row + 1 == trow && col + 1 == tcol) {
      if (board[trow][tcol] > -1) {
        r = 2;
      }
    }

    // 2 steps forward
    if (row + 2 == trow && col == tcol) {
      if (
        piece.mcount < 1
        && board[row + 1][col] == -1 
        && board[trow][tcol] == -1
      ) {
        r = 2;
      }
    }
  }

  return r;
}

void promotion() {
  int id = board[trow][tcol];
  struct Piece piece = pieces[id];

  if (  
    piece.team == WHITE
    && piece.name == PAWN
    && trow == 0
  ) {
    printf("Which piece do you want to promote?\n");
    printf("1. queen\n 2. bishop\n 3. knight\n 4. rook\n");

    int n;

    scanf("%d", &n);

    if (n == 1) {
      struct Piece queen = {QUEEN, WHITE, "♕", 0};
      pieces[id] = queen;
    } else if (n == 2) {
      struct Piece bishop = {BISHOP, WHITE, "♗", 0};
      pieces[id] = bishop;
    } else if (n == 3) {
      struct Piece knight = {KNIGHT, WHITE, "♘", 0};
      pieces[id] = knight;
    } else if (n == 4) {
      struct Piece rook = {ROOK, WHITE, "♖", 0};
      pieces[id] = rook;
    }
  }

  if (  
    piece.team == BLACK
    && piece.name == PAWN
    && trow == ROW_CNT - 1
  ) {
    printf("Which piece do you want to promote?\n");
    printf("1. queen\n 2. bishop\n 3. knight\n 4. rook\n");

    int n;

    scanf("%d", &n);

    if (n == 1) {
      struct Piece queen = {QUEEN, BLACK, "♛", 0};
      pieces[id] = queen;
    } else if (n == 2) {
      struct Piece bishop = {BISHOP, BLACK, "♝", 0};
      pieces[id] = bishop;
    } else if (n == 3) {
      struct Piece knight = {KNIGHT, BLACK, "♞", 0};
      pieces[id] = knight;
    } else if (n == 4) {
      struct Piece rook = {ROOK, BLACK, "♜", 0};
      pieces[id] = rook;
    }
  }
}

int rook() {
  int id = board[row][col];
  struct Piece piece = pieces[id];
  int r = 0;

  // up
  if (trow < row && col == tcol) {
    int tmp = 2;

    for (int r = row - 1; r > trow; r--) {
      if (board[r][col] > -1) {
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
      if (board[r][col] > -1) {
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
      if (board[row][c] > -1) {
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
      if (board[row][c] > -1) {
        tmp = 0;
        break;
      }
    }

    r = tmp;
  }

  return r;
}

int getknight(int row, int col) {

}

int knight() {
  int id = board[row][col];
  struct Piece piece = pieces[id];
  int r = 0;

  // up
  if (row - 2 == trow && col - 1 == tcol) {
    r = 2;
  }

  if (row - 2 == trow && col + 1 == tcol) {
    r = 2;
  }

  // down
  if (row + 2 == trow && col - 1 == tcol) {
    r = 2;
  }

  if (row + 2 == trow && col + 1 == tcol) {
    r = 2;
  }

  // left
  if (row - 1 == trow && col - 2 == tcol) {
    r = 2;
  }

  if (row + 1 == trow && col - 2 == tcol) {
    r = 2;
  }

  // right
  if (row - 1 == trow && col + 2 == tcol) {
    r = 2;
  }

  if (row + 1 == trow && col + 2 == tcol) {
    r = 2;
  }

  return r;
}

int bishop() {
  int id = board[row][col];
  struct Piece piece = pieces[id];
  int r = 0;

  if (abs(tcol - col) == abs(trow - row)) {
    // tl
    if (tcol - col < 0 && trow - row < 0) {
      int x = col - 1;
      int y = row - 1;
      int tmp = 2;

      while (x > tcol && y > trow) {
        if (board[y][x] > -1) {
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
        if (board[y][x] > -1) {
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
        if (board[y][x] > -1) {
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
        if (board[y][x] > -1) {
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
  int id = board[row][col];
  struct Piece piece = pieces[id];
  int r = 0;

  // up
  if (trow > row && col == tcol) {
    int tmp = 2;

    for (int r = row + 1; r < trow; r++) {
      if (board[r][col] > -1) {
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
      if (board[r][col] > -1) {
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
      if (board[row][c] > -1) {
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
      if (board[row][c] > -1) {
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
        if (board[y][x] > -1) {
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
        if (board[y][x] > -1) {
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
        if (board[y][x] > -1) {
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
        if (board[y][x] > -1) {
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
      if (board[r][c] > -1) {
        for (int i = 0; i < PIECE_CNT; i++) {
          if (i == board[r][c]) {
            printf("%s ", pieces[i].symbol);
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