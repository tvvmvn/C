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
  int mcount; // castling, 2 move
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
void chkend();
void choose_piece();
void choose_target();
int pawn();

// special rules
void promotion();

// helper
void getcrds(char[2], int*, int*);

// movement of each piece;
void setlegal();
int rook();
int knight();
int bishop();
int queen();
int king();

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
    int valid = chkpiece();
    
    if (!valid) {
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
    printf("► [%c%c] choose target");
    
    // user inputs b6, convert it into crds.
    scanf("%s", input);
    getcrds(input, &r, &c);
    
    // validate target
    int r = 1;

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
}

void chkend() {
  if (!end) {
    turn = turn == WHITE ? BLACK : WHITE;
  } else {
    printBoard();
    printf("► %s WIN!\n", turn == BLACK ? "Black" : "White");
  }
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