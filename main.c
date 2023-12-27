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

void printBoard(struct Piece pieces[4], int board[4][4]) {
  for (int r=0; r<4; r++) {
    for (int c=0; c<4; c++) {
      // thare is a piece
      if (board[r][c] != 0) {
        for (int i=0; i<4; i++) {
          if (pieces[i].id == board[r][c]) {
            printf("%c ", pieces[i].name);
          }
        }
      // empty cell
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }
}

int main() {
  int row;
  char col;
  int row_d;
  char col_d;
  int turn = 1;
  int n;
  int m;

  struct Piece pieces[4] = {
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

  // PLAY
  while (1) {
    // Print board
    printBoard(pieces, board);

    turn = turn == 1 ? 2 : 1;
    
    // Choose a piece
    while (1) {
      printf("choose a piece to move\n");


      scanf("%d %c", &row, &col);

      if (col == 'a') n = 0;
      if (col == 'b') n = 1;
      if (col == 'c') n = 2;
      if (col == 'd') n = 3;

      if (board[row][n] == 0) {
        printf("empty cell. try again\n");
      } else {
        int stop = 0;

        for (int i=0; i<4; i++) {
          if (board[row][n] == pieces[i].id) {
            if (pieces[i].team == turn) {
              stop = 1;
            } else { // wrong team 
              printf("not your team. try again\n");
            }
          }
        }

        if (stop) {
          break;
        }
      }
    }

    // Choose a destination
    while (1) {
      printf("choose dest\n");

      scanf("%d %c", &row_d, &col_d);

      if (col_d == 'a') m = 0;
      if (col_d == 'b') m = 1;
      if (col_d == 'c') m = 2;
      if (col_d == 'd') m = 3;

      int r = row == row_d && n + 1 == m;

      // validate dest
      if (r == 0) {
        printf("Not takeable. try again\n");
      } else {
        int stop = 0;
        int id = board[row_d][m];

        if (id == 0) {
          break;
        }

        for (int i=0; i<10; i++) {
          if (pieces[i].id == id) {
            if (pieces[i].team != turn) { // take enemy
              stop = 1;
            } else {
              printf("already a piece. try again\n");
            }
          }
        }

        if (stop) {
          break;
        }
      }
    }

    // move
    int temp = board[row][n];

    board[row][n] = 0;
    board[row_d][m] = temp;
  }
}