#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


/*
  CHESS - realworld rules

  # Team
  Black and White,
  and White always start first
  
  # Pieces
  King, Queen, Bishop, Knight, Rook, Pawn

  # Movement of pieces
  They have unique movement for each piece.

  # Special Rules
  1 Promotion
  2 En passant
  3 Castling

  # Game end
  1 Checkmate 
  2 Time Over (Draw)
*/


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

// Piece template
struct Piece {
  enum Pieces name;
  enum Team team;
  char symbol[4];
  int crds[2];
  int legal[8][8];
};

enum Team turn = WHITE;


/* function declarations */


// basic flow
void choose_piece();
void choose_target();
void move();
void isckmate(enum Team);
void draw();

// special rules
void promotion();
void en_passant();
void castling();

// define movements
void setlegal();
void pawnmv(struct Piece*);
void knightmv(struct Piece*);
void rookmv(struct Piece*);

// helper
int getckinfo(enum Team, int, int);
void getcrds(char[2], int*, int*);

// render
void printboard();


/* entry point */


int main() {}


/* basic flow */


void choose_piece() {
  while (1) {
    // ask user to choose a piece to move.
    printf("choose piece to move\n");

    // White user inputs b7, convert it to crds
    getcrds("b7", &r, &c);

    // validation check 
    int state = getckinfo(turn, r, c);

    if (state == 1) {
      break;
    } else {
      // error message
      printf("incorrect piece!");
    }
  }
}

void choose_target() {
  while (1) {
    printf("choose target");

    // user inputs b6, convert it into crds.
    getcrds("b6", &tr, &tc);

    struct Piece* piece = getpiecebycrds(r, c);

    if (piece->legal[tr][tc] == 1) {
      break;
    } else {
      printf("wrong target!");
    }
  }
}

void move() {
  piece->crds[0] = tr;
  piece->crds[1] = tc;
}

void isckmate(enum Team team) {
  // 1 CHECKMATE

  // WHITE isckmate first, copy white King's legal
  struct Piece king;

  if (team == WHITE) {
    king = pieces[0];
  } else {
    king = pieces[16];
  }

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      // In check that king's can take,
      if (king.legal[r][c] == 1) {
        for (int i = 0; i < PIECE_CNT; i++) {
          // if opponent piece could take there
          if (
            pieces[i].team != team
            && pieces[i].legal[r][c] == king.legal[r][c]
          ) {
            king.legal[r][c] = 0; // remove that check.
          }
        }
      }
    }
  }

  // if king has check to take, game goes on!
  int checkmate = 1;

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if (king.legal[r][c] == 1) {
        checkmate = 0;
      }
    }
  }

  if (checkmate) {
    return team;
  } 
  
  return 0;
}

void draw() {
  // game count bigger than 100 times
  if (gcount > 100) return 1;

  return 0;
};

/* Special Rules */

void en_passant() {
  // user try 2 step forward.

  // if it is pawn's first movement
  if (pawn.mcount < 1) {
    // pawn moved 2 step forward.

    // then increase mcount.
    pawn.mcount++;
  }

  // WHITE en passant

  // user is trying to move pawn for the first time.
  if (pawn.mcount < 1) {
    // moves pawn 2 step forward.
  }

  // if pawn has moved 2 stop forward
  if (previous_rows + 2 == pawn.crds[0]) { 
    activated_check = "b3";
    gcount = 89; // save game count 
    prev_count = gcount;
  }

  // opposite turn, so
  gcount++;

  // opposite pawn just after activated check
  if (prev_gcount + 1 == gcount) {
    if (pawn.crds == "b3") {
      // remove opposite pawn from board.
    }
  }

  // game goes on..
};

void castling() {
  // WHITE castling

  // if user choose king then choose rook 
  if (piece == king && target == pawn) {};

  // ask user like "would you do castling?"
  printf("castling or not");

  // if user accept it, there are 2 options - left/right rook.

  // 1 exchange king with right rook
  if (king.mcount < 1 && rook.mcount < 1) {
    if (getpcbycrds(7, 5) == NULL && getpcbycrds(7, 6) == NULL) {
      // ok
      king.crds[1] += 2;
      rook.crds[1] -= 2;
    }
  }

  // 2 exchange king with left rook
};

void promotion() {
  // WHITE promotion

  // pawn reaches first row.
  if (pawn.crds[0] == 0) {
    printf("choose piece to promote: queen, bishop, knight and king.\n");
  }

  // user chose queen.
  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].crds == pawn.crds) {
      struct Piece piece = {QUEEN, ..}; // queen

      // change pawn to queen.
      pieces[i] = queen;
    }
  }

  // then opposite's turn
};


/* Define movements */


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
}

void pawnmv(struct Piece* pawn) {
  int r = pawn->crds[0];
  int c = pawn->crds[1];

  // WHITE
  // up
  if (getckinfo(pawn->team, r - 1, c) == 0) {
    pawn->legal[r - 1][c] = 1;
  }

  // top-left
  if (getckinfo(pawn->team, r - 1, c - 1) == -1) {
    pawn->legal[r - 1][c - 1] = 1;
  }

  // top-right
  if (getckinfo(pawn->team, r - 1, c + 1) == -1) {
    pawn->legal[r - 1][c + 1] = 1;
  }

  // BLACK
}

void knightmv(struct Piece* knight) {
  int r = knight->crds[0];
  int c = knight->crds[1];

  // top
  if (getckinfo(knight->team, r - 2, c - 1) <= 0) {
    knight->legal[r - 2][c - 1] = 1;
  }

  if (getckinfo(knight->team, r - 2, c + 1) <= 0) {
    knight->legal[r - 2][c + 1] = 1;
  }
}

void rookmv(struct Piece* rook) {
  // up
  for (int r = rook->crds[0] - 1; r >= 0; r--) {
    int c = rook->crds[1];

    if (getckinfo(rook->team, r, c) == -1) {
      rook->legal[r][c] = 1;
      break;
    }
    
    if (getckinfo(rook->team, r, c) == 1) {
      break;
    }

    if (getckinfo(rook->team, r, c) == 0) {
      rook->legal[r][c] = 1;
    }
  }

  // left
  for (int c = rook->crds[1] - 1; c >= 0; c--) {
    int r = rook->crds[0];

    if (getckinfo(rook->team, r, c) == -1) {
      rook->legal[r][c] = 1;
      break;
    }
    
    if (getckinfo(rook->team, r, c) == 1) {
      break;
    }

    if (getckinfo(rook->team, r, c) == 0) {
      rook->legal[r][c] = 1;
    }
  }
}


/* Helper */


// convert user input to crds
void getcrds(char input[2], int *r, int *c) {
  // row
  char rows[] = "12345678";

  for (int i = 0; i < 8; i++) {
    if (input[1] == rows[i]) *r = i;
  }

  // col
  char cols[] = "abcdefg";

  for (int i = 0; i < 8; i++) {
    if (input[0] == cols[i]) *c = i;
  }
}

struct Piece* getpcbycrds(int r, int c) {
  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].legal[0] == r && pieces[i].legal[1] == c) {
      return &pieces[i];
    }
  } 

  return NULL;
};

int getckinfo(enum Team team, int r, int c) {
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


/* render */


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