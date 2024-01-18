#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct Piece {
  int id; // 4
  char name[10]; // 11
};

int main() {
  struct Piece piece;

  printf("%lu\n", sizeof(piece)); // 16
  printf("%lu\n", sizeof(piece.id)); // 4
  printf("%lu\n", sizeof(piece.name)); // 10
  printf("%lu\n", strlen(piece.name)); // 2
  printf("%d\n", piece.id); // random integer
  printf("%s\n", piece.name); // xf8xf7
}