#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Piece {
  char name[10];
  char symbol[4];
};

const struct Piece pieces[4] = {
  {"pawn", "♝"},
  {"pawn", "♝"},
  {"pawn", "♝"},
  {"pawn", "♝"},
};

int main() {
  printf("%s\n", pieces[0].name);
  printf("%s\n", pieces[0].symbol);
}
