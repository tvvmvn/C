#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Piece {
  int id;
  int legal[8][8];
};

int main() {
  // struct Piece piece;
  struct Piece pieces[1] = {
    {1}
  };

  struct Piece wk = pieces[0];

  wk.legal[6][0] = 1;

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      printf("%d", wk.legal[r][c]);
    }
    printf("\n");
  }
}