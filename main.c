#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


struct Piece {
  int id;
  char name;
  int team; // 1 or 2
  int status; // 0 or 1
  int selected; // 0 or 1
};

int main() {
  int row;
  char col;
  int row_d;
  char col_d;

  struct Piece pieces[] = {
    {1, 'a', 1, 1, 0},
    {2, 'b', 1, 1, 0},
    {3, 'c', 2, 1, 0},
    {4, 'd', 2, 1, 0},
  };

  int board[4][4] = {
    {1, 0, 2, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 3, 0, 4},
  };

  for (int r=0; r<4; r++) {
    for (int c=0; c<4; c++) {
      if (board[r][c] != 0) {
        for (int i=0; i<4; i++) {
          if (pieces[i].id == board[r][c]) {
            printf("%c ", pieces[i].name);
          }
        }
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }

  printf("choose a piece to move\n");

  scanf("%d %c", &row, &col);

  printf("%d, %c\n", row, col);

  int n;

  if (col == 'a') n = 0;
  if (col == 'b') n = 1;
  if (col == 'c') n = 2;
  if (col == 'd') n = 4;

  printf("%d, %d\n", row, n);

  printf("choose dest\n");

  scanf("%d %c", &row_d, &col_d);

  int m;

  if (col_d == 'a') m = 0;
  if (col_d == 'b') m = 1;
  if (col_d == 'c') m = 2;
  if (col_d == 'd') m = 4;

  int temp = board[row][n];

  board[row][n] = 0;
  board[row_d][m] = temp;

  for (int r=0; r<4; r++) {
    for (int c=0; c<4; c++) {
      if (board[r][c] != 0) {
        for (int i=0; i<4; i++) {
          if (pieces[i].id == board[r][c]) {
            printf("%c ", pieces[i].name);
          }
        }
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }
}