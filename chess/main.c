#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main() {

  // CHECKMATE
  // king has 3 states unlike other pieces: -1, 0, 1 
  // when no 1, it's checkmate.

  // top-left
  setstate(king.crds[0] - 1, king.crds[1] - 1);
  // top-center
  setstate(king.crds[0] - 1, king.crds[1]);
  // top-right
  setstate(king.crds[0] - 1, king.crds[1] + 1);
}

int setstate(r, c) {
  for (int i = 0; i < 32; i++) {
    if (pieces[i].team == BLACK) {
      if (pieces[i].legal[r][c] == 1) {
        king.legal[r][c] = -1;
      }
    }

    if (pieces[i].team == WHITE) {
      if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
        king.legal[r][c] = 0;
      }
    }

    if (pieces[i].team == BLACK) {
      if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
        king.legal[r][c] = 1;
      }
    }
  }
}
