#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
  state of point

  0 not legal
  1 (takeable) empty or opponent
  2 same team (potentially takeable by opponent)
*/

int main() {}

// # Get points of king
void getpoints() {
  // top-left
  int r = king.crds[0] - 1;
  int c = king.crds[1] - 1;

  int dangerzone = isdangerzone(r, c);

  if (dangerzone) {
    king.points[r][c] = 0;
  } else {
    int id = board[r][c];
  
    // empty
    if (!id) {
      king.points[r][c] = 1;
    } else {
      struct Piece piece = getpiecebyid(id);

      if (piece.team == WHITE) {
        king.points[r][c] = 0;
      } else {
        king.points[r][c] = 1;
      }
    }
  }
}

// # checkmate
void ischeckmate() {
  // 1 king in threat now, then
  if (isdangerzone(king.crds[0], king.crds[1])) {
    /*
    2 freeze all

    3 
    3-1. only 1 threat
      3-1-1. saver exists
        3-1-1-1. king has [1]
        unfreeze him.
        3-1-1-2. king has no [1]
        unfreeze him.
      
      3-1-2. saver doesn't exists
        3-1-2-1. king has [1]
        keep playing
        3-1-2-2. king has no [1]
        checkmate!

    3-2. more than 2 threats 
      3-2-1. king has [1]
      keep playing
      3-2-2. king has no [1] 
      checkmate!
    */
  }
}

// # whether check is danger zone or not
void isdangerzone(int r, int c) {
  int n = 0;

  for (int i = 0; i < 32; i++) {
    if (pieces[i].team == BLACK) {
      if (
        pieces[i].points[r][c] == 1 
        || pieces[i].points[r][c] == 2
      ) {
        n = 1;
      }
    }
  }

  return n;
}

