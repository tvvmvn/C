#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main() {}

// # whether check is danger zone or not
void isdangerzone(int r, int c) {
  int n = 0;

  for (int i = 0; i < 32; i++) {
    if (pieces[i].team == BLACK) {
      if (pieces[i].points[r][c] == 1) {
        n = 1;
      }
    }
  }

  return n;
}

// # Get points of king
void getpoints() {
  // top-left
  int r = king.crds[0] - 1;
  int c = king.crds[1] - 1;

  int id = board[r][c];

  // empty
  if (!id) {
    int dangerzone = isdangerzone(r, c);

    if (dangerzone) {
      king.points[r][c] = 0;
    } else {
      king.points[r][c] = 1;
    }
  } else {
    struct Piece piece = getpiecebyid(id);

    if (piece.team == WHITE) {
      king.points[r][c] = 0;
    } else {
      king.points[r][c] = 1;
    }
  }
}

// # checkmate
void isckmate() {
  // king in danger zone now
  if (isdangerzone(king.crds[0], king.crds[1])) {
    // and no place to avoid! -> all 0
  }
}