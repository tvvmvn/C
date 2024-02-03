#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main() {

  // CHECKMATE

  // 1. king has place to avoid ?

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if (king.legal[r][c] == 1) {
        for (int i = 0; i < 32; i++) {
          if (pieces[i].legal[r][c] == 1) {
            king.legal[r][c] = 0;
          }
        }
      }
    }
  }

  // .. if king has legal, not checkmate!


  // 2. can't remove threat?

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if (pieces[i].legal[r][c] == 1) {
        if (king.crds[0] == r && king.crds[1] == c) {
          threat = pieces[i];
        }
      }
    }
  }

  if (pieces[i].legal[r][c] == 1) {
    if (threat.crds[0] == r && threat.crds[1] == c) {
      // removing threat's done!
      pieces[i].crds[0] = r;
      pieces[i].crds[1] = c;
    }
  }
}
