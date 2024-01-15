#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Piece {
  int name;
  int team;
};

int main() {
  struct Piece piece;

  printf("%d %d\n", piece.name, piece.team);
}
