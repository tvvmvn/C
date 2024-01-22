#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// chess pieces
enum Pieces {
  KING,
  QUEEN,
  BISHOP,
  KNIGHT,
  ROOK,
  PAWN
};

// 2 team - black and white
enum Team {
  WHITE = 1,
  BLACK
};

// piece template
struct Piece {
  enum Pieces name;
  enum Team team;
  char symbol[4];
  int crds[2];
  int legal[8][8];
};

// total count of pieces 
const int PIECE_CNT = 32;


// rows and cols
char rows[] = "12345678";
char cols[] = "abcdefgh";

// points to a piece
struct Piece* piece;

// 32 pieces - 16 white, 16 black
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

// White always starts first.
enum Team turn = WHITE;

/*
  function declarations.
  .. 
*/

// basic flow
void choose_piece();
void choose_target();
void move();
void chkend();

// special rules
void promotion();
void en_passant();
void castling();

// helper
void setlegal();
void getpiece(int, int);
int chkstate(enum Team, int, int);

// define movements
void pawnmv(struct Piece*);
void knightmv(struct Piece*);
void rookmv(struct Piece*);

// render
void printboard();


// program entry point
int main() {}

void choose_piece() {
  while (1) {
    // ask user to choose a piece to move.
    printf("choose piece to move\n");

    // White user inputs b7 - pawn.
    // transform string b7 to integer crds

    struct Piece* piece = getpiece(r, c);

    // validation check 
    if (piece != NULL) {
      if (piece->team != turn) {
        printf("wrong piece!");
      } else {
        break;
      }
    } else {
      // error message
      printf("no piece!");
    }
  }
}

void choose_target() {
  while (1) {
    printf("choose target");

    // user inputs b6
    // transforms b6 to integer crds.
    int tr = 5;
    int tc = 0;

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

void chkend() {
  // WHITE checkmate first, copy white King's legal
  struct Piece wk = pieces[0];

  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].team == BLACK) {
      for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
          // in check that king's can take,
          if (wk.legal[r][c] == 1) {
            // if opponent piece could take there
            if (wk.legal[r][c] == pieces[i].legal[r][c]) {
              wk.legal[r][c] = 0; // remove that check.
            }
          }
        }
      }
    }
  }

  // if king has check to take, game goes on!
  int checkmate = 1;

  for (int r = 0; r < 8; r++) {
    for (int c = 0; c < 8; c++) {
      if (wk.legal[r][c] == 1) {
        checkmate = 0;
      }
    }
  }
}

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
    if (getpiece(7, 5) == NULL && getpiece(7, 6) == NULL) {
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

// set legal
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

struct Piece getpiece() {}

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