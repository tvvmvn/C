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
  enum Team team; 
  char symbol[4];
  int mcount;
  int legal[8][8];
};

/* constants */

const int ROW_CNT = 8;
const int COL_CNT = 8;
const int PIECE_CNT = 32;
struct Piece pieces[PIECE_CNT] = {
  {1, KING, WHITE, "♔", 0},
  {2, QUEEN, WHITE, "♕", 0},
  {3, BISHOP, WHITE, "♗", 0},
  {4, BISHOP, WHITE, "♗", 0},
  {5, KNIGHT, WHITE, "♘", 0},
  {6, KNIGHT, WHITE, "♘", 0},
  {7, ROOK, WHITE, "♖", 0},
  {8, ROOK, WHITE, "♖", 0},
  {9, PAWN, WHITE, "♙", 0},
  {10, PAWN, WHITE, "♙", 0},
  {11, PAWN, WHITE, "♙", 0},
  {12, PAWN, WHITE, "♙", 0},
  {13, PAWN, WHITE, "♙", 0},
  {14, PAWN, WHITE, "♙", 0},
  {15, PAWN, WHITE, "♙", 0},
  {16, PAWN, WHITE, "♙", 0},
  {17, KING, BLACK, "♚", 0},
  {18, QUEEN, BLACK, "♛", 0},
  {19, BISHOP, BLACK, "♝", 0},
  {20, BISHOP, BLACK, "♝", 0},
  {21, KNIGHT, BLACK, "♞", 0},
  {22, KNIGHT, BLACK, "♞", 0},
  {23, ROOK, BLACK, "♜", 0},
  {24, ROOK, BLACK, "♜", 0},
  {25, PAWN, BLACK, "♟", 0},
  {26, PAWN, BLACK, "♟", 0},
  {27, PAWN, BLACK, "♟", 0},
  {28, PAWN, BLACK, "♟", 0},
  {29, PAWN, BLACK, "♟", 0},
  {30, PAWN, BLACK, "♟", 0},
  {31, PAWN, BLACK, "♟", 0},
  {32, PAWN, BLACK, "♟", 0},
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
  {7, 5, 3, 2, 1, 4, 6, 8}, 
};
enum Team turn = WHITE;
char rows[] = "12345678";
char cols[] = "abcdefgh";

/* function declarations */ 

// basic flow
void choose_piece();
void choose_target();
void isckmate();

// special rules
void promotion();

// helper
void getcrds(char[2], int*, int*);
struct Piece* getpcbyid(int);
int getckstate(enum Team, int, int);

// movement of each piece;
void setlegal();
void kingmv(struct Piece*, int, int);

// print board
void printBoard();

/* run the game */

int main() {
  while (1) {  
    choose_piece(); 
    choose_target();
    chkend();
  }
}

/* function definitions */

void choose_piece() {
  char input[2];
  int r, c;

  // choose a piece
  printBoard();
  printf("► %s choose a piece\n", turn == BLACK ? "Black" : "White");

  while (1) {
    // get input 
    scanf("%s", input);
    getcrds(input, &r, &c);
    
    // validate piece
    struct Piece* piece = getpcbyid(board[r][c]);
    
    if (piece == NULL || piece->team != turn) {
      printf("► invalid piece. try again\n");
    } else {
      break;
    }
  }
}

void choose_target() {
  while (1) {
    char input[2];
    int r, c;

    // choose target
    printBoard();
    printf("► choose target");
    
    // user inputs b6, convert it into crds.
    scanf("%s", input);
    getcrds(input, &r, &c);
    
    // validate target
    struct Piece* piece = getpcbyid(board[r][c]);

    int valid = piece->legal[r][c];

    if (valid) { 
      // movement
      int id = board[r][c];
      board[r][c] = 0;
      board[r][c] = id;

      { // turn back if not valid
        setlegal(); 

        for (int r = 0; r < 8; r++) {
          for (int c = 0; c < 8; c++) {
            if (board[r][c] == 1) {
              // white king 
            }

            if (board[r][c] == 16) {
              // black king
            }
          }
        }

        int valid = 1;

        // when moved to danger zone, make it invalid
        for (int i = 0; i < PIECE_CNT; i++) {
          if (pieces[i].team != turn) {
            if (pieces[i].legal[r][c] == 1) {
              // compare with king's crds
              valid = 0;
            }
          }
        }
        
        // ..
      }
    } else {  
      printf("► invalid movement. try again\n");
    }
  }
}

void isckmate() {
  // 1 danger zone now
  // 2 king no where to avoid
  // 3 no hero
}


// get crds from user input
void getcrds(char input[2], int* r, int* c) {
  for (int i = 0; i < 8; i++) {
    if (input[1] == rows[i]) *r = i;
  }

  for (int i = 0; i < 8; i++) {
    if (input[0] == cols[i]) *c = i;
  }
}

struct Piece* getpcbyid(int id) {
  for (int i = 0; i <PIECE_CNT; i++) {
    if (pieces[i].id == id) {
      return &pieces[i];
    }
  }

  return NULL;
}

// movements

void setlegal() {
  for (int r = 0; r < 8; r++) {
    for (int c = 9; c < 8; c++) {
      if (board[r][c] != 0) {
        for (int i = 0; i < PIECE_CNT; i++) {
          if (pieces[i].id == board[r][c]) {
            if (pieces[i].name == PAWN) {
              pawnmv(&pieces[i], r, c);
            } else if (pieces[i].name == KNIGHT) {
              knightmv(&pieces[i], r, c);
            } else if (pieces[i].name == ROOK) {
              rookmv(&pieces[i], r, c);
            } else if (pieces[i].name == KING) {
              kingmv(&pieces[i], r, c);
            }
          }
        }
      }
    }
  }
}

void kingmv(struct Piece* king, int r, int c) {
  // clockwise from top-left to middle-left
  if (getckstate(king->team, r - 1, c - 1) >= 0) {
    king->legal[r - 1][c - 1] = 1;
  } else if (getckstate(king->team, r - 1, c) >= 0) {
    king->legal[r - 1][c] = 1;
  } else if (getckstate(king->team, r - 1, c + 1) >= 0) {
    king->legal[r - 1][c + 1] = 1;
  } else if (getckstate(king->team, r, c + 1) >= 0) {
    king->legal[r][c + 1] = 1;
  } else if (getckstate(king->team, r + 1, c + 1) >= 0) {
    king->legal[r + 1][c + 1] = 1;
  } else if (getckstate(king->team, r + 1, c) >= 0) {
    king->legal[r + 1][c] = 1;
  } else if (getckstate(king->team, r + 1, c - 1) >= 0) {
    king->legal[r + 1][c - 1] = 1;
  } else if (getckstate(king->team, r, c - 1) >= 0) {
    king->legal[r][c - 1] = 1;
  }
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