#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/* enums */

enum Pieces {
  KING,
  QUEEN,
  BISHOP,
  KNIGHT,
  ROOK,
  PAWN
};

enum Team {
  WHITE = 1,
  BLACK
};

/* struct */

struct Piece {
  enum Pieces name;
  enum Team team;
  char symbol[4];
  int crds[2];
  int legal[8][8];
};

/* contants */

const int PIECE_CNT = 32;

/* variables */

char rows[] = "12345678";
char cols[] = "abcdefgh";
struct Piece* piece;

struct Piece pieces[PIECE_CNT] = {
  {KING, WHITE, "♔", {7, 4}},
  {QUEEN, WHITE, "♕", {7, 3}},
  {BISHOP, WHITE, "♗", {7, 2}},
  {BISHOP, WHITE, "♗", {7, 5}},
  {KNIGHT, WHITE, "♘", {7, 1}},
  {KNIGHT, WHITE, "♘", {7, 6}},
  {ROOK, WHITE, "♖", {7, 0}},
  {ROOK, WHITE, "♖", {7, 7}},
  {PAWN, WHITE, "♙", {6, 0}},
  {PAWN, WHITE, "♙", {6, 1}},
  {PAWN, WHITE, "♙", {6, 2}},
  {PAWN, WHITE, "♙", {6, 3}},
  {PAWN, WHITE, "♙", {6, 4}},
  {PAWN, WHITE, "♙", {6, 5}},
  {PAWN, WHITE, "♙", {6, 6}},
  {PAWN, WHITE, "♙", {6, 7}},
  {KING, BLACK, "♚", {0, 4}},
  {QUEEN, BLACK, "♛", {0, 3}},
  {BISHOP, BLACK, "♝", {0, 2}},
  {BISHOP, BLACK, "♝", {0, 5}},
  {KNIGHT, BLACK, "♞", {0, 1}},
  {KNIGHT, BLACK, "♞", {0, 6}},
  {ROOK, BLACK, "♜", {0, 0}},
  {ROOK, BLACK, "♜", {0, 7}},
  {PAWN, BLACK, "♟", {1, 0}},
  {PAWN, BLACK, "♟", {1, 1}},
  {PAWN, BLACK, "♟", {1, 2}},
  {PAWN, BLACK, "♟", {1, 3}},
  {PAWN, BLACK, "♟", {1, 4}},
  {PAWN, BLACK, "♟", {1, 5}},
  {PAWN, BLACK, "♟", {1, 6}},
  {PAWN, BLACK, "♟", {1, 7}},
};

enum Team turn = WHITE;

/* function declarations */

void setlegal();
int chkstate(enum Team, int, int);
void pawnmv(struct Piece*);
void knightmv(struct Piece*);
void rookmv(struct Piece*);
void printboard();

/* run the game */

int main() {
  setlegal();

  printboard();

  // we move pawn from (6, 0) to (5, 0).
  int r = 6;
  int c = 0;

  // valid check
  int valid = 0;

  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
      if (pieces[i].team == turn) {
        piece = &pieces[i];
        valid = 1;
      }
    }
  }

  // move
  if (valid) {
    if (piece->legal[5][0] == 1) {
      piece->crds[0] = 5;
      piece->crds[1] = 0;
    } else {
      printf("invalid!\n");
    }
  }

  printboard();
}

/* function definitions */

void setlegal() {
  for (int i = 0; i < PIECE_CNT; i++) {  
    if (pieces[i].name == PAWN) {
      pawnmv(&pieces[i]);
    } else if (pieces[i].name == KNIGHT) {
      knightmv(&pieces[i]);
    } else if (pieces[i].name == ROOK) {
      rookmv(&pieces[i]);
    }
  }
  
  // for (int r = 0; r < 8; r++) {
  //   for (int c = 0; c < 8; c++) {
  //     printf("%d ", pieces[15].legal[r][c]);
  //   }
  //   printf("\n");
  // }
}

int chkstate(enum Team team, int r, int c) {
  int state = 0;

  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
      if (pieces[i].team == team) {
        state = 1;
      } else {
        state = -1;
      }
    }
  }

  return state;
}

void pawnmv(struct Piece* pawn) {
  int r = pawn->crds[0];
  int c = pawn->crds[1];

  // WHITE
  // up
  if (chkstate(pawn->team, r - 1, c) == 0) {
    pawn->legal[r - 1][c] = 1;
  }

  // top-left
  if (chkstate(pawn->team, r - 1, c - 1) == -1) {
    pawn->legal[r - 1][c - 1] = 1;
  }

  // top-right
  if (chkstate(pawn->team, r - 1, c + 1) == -1) {
    pawn->legal[r - 1][c + 1] = 1;
  }

  // BLACK
}

void knightmv(struct Piece* knight) {
  int r = knight->crds[0];
  int c = knight->crds[1];

  // top
  if (chkstate(knight->team, r - 2, c - 1) <= 0) {
    knight->legal[r - 2][c - 1] = 1;
  }

  if (chkstate(knight->team, r - 2, c + 1) <= 0) {
    knight->legal[r - 2][c + 1] = 1;
  }
}

void rookmv(struct Piece* rook) {
  // up
  for (int r = rook->crds[0] - 1; r >= 0; r--) {
    int c = rook->crds[1];

    if (chkstate(rook->team, r, c) == -1) {
      rook->legal[r][c] = 1;
      break;
    }
    
    if (chkstate(rook->team, r, c) == 1) {
      break;
    }

    if (chkstate(rook->team, r, c) == 0) {
      rook->legal[r][c] = 1;
    }
  }

  // left
  for (int c = rook->crds[1] - 1; c >= 0; c--) {
    int r = rook->crds[0];

    if (chkstate(rook->team, r, c) == -1) {
      rook->legal[r][c] = 1;
      break;
    }
    
    if (chkstate(rook->team, r, c) == 1) {
      break;
    }

    if (chkstate(rook->team, r, c) == 0) {
      rook->legal[r][c] = 1;
    }
  }
}

void printboard() {
  // top space
  printf("\n");

  // rows
  for (int r = 0; r < strlen(rows); r++) {
    printf("%c", rows[r]);

    for (int c = 0; c < strlen(cols); c++) {
      int idx = -1;

      for (int i = 0; i < PIECE_CNT; i++) {
        if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
          idx = i;
          break;
        }
      }
      
      if (idx > -1) {
        printf(" %s", pieces[idx].symbol);
      } else {
        if ((r + c) % 2 == 0) {
          printf(" ◦");
        } else {
          printf(" •");
        }
      }
    }

    printf("\n");
  }

  // last row
  printf(" ");

  for (int c = 0; c < strlen(cols); c++) {
    printf(" %c", cols[c]);
  }

  printf("\n");

  // bottom space
  printf("\n");
}