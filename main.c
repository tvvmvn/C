#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main() {
  struct Piece pieces[32] = {};

  // a pawn in a7 now and it can move to a5, a6
  char rows[] = "12345678";
  char cols[] = "abcdefgh";

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      for (int i = 0; i < 32; i++) {
        if (
          pieces[i].crds[0] == cols[r]
          && pieces[i].crds[1] == rows[c]
        ) {

          // {r, c} is current position.
          
          if (pieces[i].name == PAWN) {
            // 1 step
            rows[r - 1];
            cols[c];

            // 2 step
            rows[r - 2];
            cols[c];

            pieces[i].legal
          }
        }
      }
    }
  }
}
