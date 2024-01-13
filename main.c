#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Piece {
  int id;
  int mcount;
};

int main() {
  struct Piece pieces[3] = {
    {0, 0},
    {1, 0},
    {2, 0},
  };

  struct Piece p = {4, 0}; // pointer

  pieces[2] = p;

  printf("%d\n", pieces[2].id);
}

