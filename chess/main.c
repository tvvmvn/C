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
  char crds[2];
};

/* constants */

const int ROW_CNT = 8;
const int COL_CNT = 8;
const int PIECE_CNT = 32;

/* variables */

struct Piece pieces[PIECE_CNT] = {
  {KING, WHITE, "♔", "e8"},
  {QUEEN, WHITE, "♕", "d8"},
  {BISHOP, WHITE, "♗", "c8"},
  {BISHOP, WHITE, "♗", "f8"},
  {KNIGHT, WHITE, "♘", "b8"},
  {KNIGHT, WHITE, "♘", "g8"},
  {ROOK, WHITE, "♖", "a8"},
  {ROOK, WHITE, "♖", "h8"},
  {PAWN, WHITE, "♙", "a7"},
  {PAWN, WHITE, "♙", "b7"},
  {PAWN, WHITE, "♙", "c7"},
  {PAWN, WHITE, "♙", "d7"},
  {PAWN, WHITE, "♙", "e7"},
  {PAWN, WHITE, "♙", "f7"},
  {PAWN, WHITE, "♙", "g7"},
  {PAWN, WHITE, "♙", "h7"},
  {KING, BLACK, "♚", "e1"},
  {QUEEN, BLACK, "♛", "d1"},
  {BISHOP, BLACK, "♝", "c1"},
  {BISHOP, BLACK, "♝", "f1"},
  {KNIGHT, BLACK, "♞", "b1"},
  {KNIGHT, BLACK, "♞", "g1"},
  {ROOK, BLACK, "♜", "a1"},
  {ROOK, BLACK, "♜", "h1"},
  {PAWN, BLACK, "♟", "a2"},
  {PAWN, BLACK, "♟", "b2"},
  {PAWN, BLACK, "♟", "c2"},
  {PAWN, BLACK, "♟", "d2"},
  {PAWN, BLACK, "♟", "e2"},
  {PAWN, BLACK, "♟", "f2"},
  {PAWN, BLACK, "♟", "g2"},
  {PAWN, BLACK, "♟", "h2"},
};
enum Team turn = WHITE;

/* functions declaration */

void printboard();

/* run the game */

int main() {  
  printboard();
}

/* function definitions */

// define legal movement
void movement() {
}

void move() {
  // We will move pawn on (6, 0) to (5, 0).
  int idx = -1;

  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].crds[0] == 6 && pieces[i].crds[1] == 0) {
      idx = i;
    }
  }

  if (idx > -1) {
    if (pieces[idx].team == turn) {

      // check legal move first
      pieces[idx].crds[0] = 5;
      pieces[idx].crds[1] = 0;
    } else {
      // err: you choose opposite piece
    }
  } else {
    // err: no piece on that crds.
  }
}

void printboard() {
  for (int r = 0; r < ROW_CNT; r++) {
    for (int c = 0; c < COL_CNT; c++) {
      int idx = -1;

      for (int i = 0; i < PIECE_CNT; i++) {
        if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
          idx = i;
          break;
        }
      }
      
      if (idx > -1) {
        printf("%s ", pieces[idx].symbol);
      } else {
        if ((r + c) % 2 == 0) {
          printf("◦ ");
        } else {
          printf("• ");
        }
      }
    }

    printf("\n");
  }
}