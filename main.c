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
  if (r == pawn->crds[0] - 1 && c == pawn->crds[1]) {
    pawn->legal[r][c] = 1;
  }
}

void knightmv(struct Piece* knight) {
  if (r == knight->crds[0] - 2 && c == knight->crds[1] - 1) {
    knight->legal[r][c] = 1;
  }

  if (r == knight->crds[0] - 2 && c == knight->crds[1] + 1) {
    knight->legal[r][c] = 1;
  }
}

// function to tell that check is takeable or not

void rookmv(struct Piece* rook) {
  // up
  for (int r = rook->crds[0]; r >= 0; r--) {
    if () { // there is a piece
      break;
    }
    rook->legal[r][rook->crds[1]] = 1;
  }
}

void bishopmv(struct Piece* bishop, int r, int c) {
  if (bishop->crds[1] == c) {
    bishop->legal[r][c] = 1;
  }

  if (bishop->crds[0] == r) {
    bishop->legal[r][c] = 1;
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