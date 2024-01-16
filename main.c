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
  int name;
  char crds[2];
  int legal[8][8];
};

/* contants */
const char rows[] = "12345678";
const char cols[] = "abcdefgh";

/* variables */

/* functions */

int main() {

  struct Piece pieces[1] = {
    {PAWN, {6, 0}}
  };

  for (int i = 0; i < 1; i++) {
    if (pieces[i].name == PAWN) {      

      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) { // (5, 0) is takeable.
          if (r == pieces[i].crds[0] - 1 && c == pieces[i].crds[1]) {
            pieces[i].legal[r][c] = 1;
          }
        }
      }
    }
  }

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      printf("%d ", pieces[0].legal[r][c]);
    }
    printf("\n");
  }
}
