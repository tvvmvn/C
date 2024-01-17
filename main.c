#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

enum Pieces {
  KING,
  QUEEN,
  BISHOP,
  KNIGHT,
  ROOK,
  PAWN
};

struct Piece {
  enum Pieces name;
  int crds[2];
  int legal[8][8];
};

/* contants */

const char rows[] = "12345678";
const char cols[] = "abcdefgh";

/* variables */

struct Piece pieces[3] = {
  {PAWN, {6, 0}},
  {KNIGHT, {7, 1}},
  {ROOK, {7, 7}},
};

/* functions */

void pawnmv(struct Piece* pawn) {
  int r = pawn->crds[0];
  int c = pawn->crds[1];

  pawn->legal[r - 1][c] = 1;
}

void knightmv(struct Piece* knight) {
  int r = knight->crds[0];
  int c = knight->crds[1];

  // top
  knight->legal[r - 2][c - 1] = 1;
  knight->legal[r - 2][c + 1] = 1;
}

/*
  3 check state code
  100 empty, 200 our forces, 300 opposite 
*/

void rookmv(struct Piece* rook) {
  // up
  for (int r = rook->crds[0]; r >= 0; r--) {
    int c = rook->crds[1];

    rook->legal[r][c] = 1;
  }

  // left
  for (int c = rook->crds[1]; c >= 0; c--) {
    int r = rook->crds[0];
    
    rook->legal[r][c] = 1;
  }
}

int main() {
  for (int i = 0; i < 3; i++) {  
    if (pieces[i].name == PAWN) {
      pawnmv(&pieces[i]);
    } else if (pieces[i].name == KNIGHT) {
      knightmv(&pieces[i]);
    } else if (pieces[i].name == ROOK) {
      rookmv(&pieces[i]);
    }
  }

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      printf("%d ", pieces[2].legal[r][c]);
    }
    printf("\n");
  }
}