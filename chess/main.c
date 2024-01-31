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

const int PIECE_CNT = 32;
// rows and cols
const char rows[] = "12345678";
const char cols[] = "abcdefgh";

enum Team turn = WHITE;
struct Piece* piece;
int gcount = 0;

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


/* function declarations */


// basic flow
void choose_piece();
void choose_target();
void chkend();

// define movements
void setlegal();
void pawnmv(struct Piece*);
void knightmv(struct Piece*);
void rookmv(struct Piece*);
void kingmv(struct Piece*);

// special rules
void promotion();
void en_passant();
void castling();

// helper
void getcrds(char[2], int*, int*);
int getckstate(enum Team, int, int);
struct Piece* getpcbycrds(int, int);
int isckmate(enum Team);
int isdrawn();

// render
void printboard();


/* entry point */

int end = 0;

int main() {
  while (1) {
    setlegal();
    chkend();

    if (end) {
      break;
    } else {
      choose_piece();
      choose_target();

      turn = turn == WHITE ? BLACK : WHITE;
    }
  }
}


/* basic flow */


void choose_piece() {
  char input[2];
  int r, c;

  printboard();

  while (1) {
    // ask user to choose a piece to move.
    printf("▶︎ %s choose piece to move\n", turn == WHITE ? "WHITE" : "BLACK");

    scanf("%s", input);

    // White user inputs b7, convert it to crds
    getcrds(input, &r, &c);

    // validation check 
    int state = getckstate(turn, r, c);

    if (state == -1) {
      piece = getpcbycrds(r, c);
      break;
    } else {
      // error message
      printf("err: incorrect piece!\n");
    }
  }
}

void choose_target() {
  char input[2];
  int r, c;

  printboard();

  while (1) {
    printf("▶︎ choose target\n");

    scanf("%s", input);

    // user inputs b6, convert it into crds.
    getcrds(input, &r, &c);

    if (piece->legal[r][c] == 1) {

      /*
        In case of king,
        check updated crds of king before printing board
        to make sure it's legal movement
      */

      piece->crds[0] = r;
      piece->crds[1] = c;

      if (piece->name == KING) {
        setlegal();

        
      }

      break;
    } else {
      printf("err: wrong target!\n");
    }
  }
}

void chkend() {
  int checkmate = isckmate(turn);
  int draw = isdrawn();

  if (checkmate != 0) {
    if (checkmate == 1) {
      // Black WIN
    } else {
      // White WIN
    }

    printboard();
    printf("▶︎ Checkmate!\n");

    end = 1;
  }

  if (draw) {
    // drawn
    printboard();
    printf("▶︎ Draw!\n");

    end = 1;
  }
}


/* Define movements */


void setlegal() {
  for (int i = 0; i < PIECE_CNT; i++) {  
    if (pieces[i].name == PAWN) {
      pawnmv(&pieces[i]);
    } else if (pieces[i].name == KNIGHT) {
      knightmv(&pieces[i]);
    } else if (pieces[i].name == ROOK) {
      rookmv(&pieces[i]);
    } else if (pieces[i].name == KING) {
      kingmv(&pieces[i]);
    }
  }
}

void pawnmv(struct Piece* pawn) {
  int r = pawn->crds[0];
  int c = pawn->crds[1];

  // WHITE
  if (pawn->team == WHITE) {
    // front
    if (getckstate(pawn->team, r - 1, c) == 0) {
      pawn->legal[r - 1][c] = 1;
    // left
    } else if (getckstate(pawn->team, r - 1, c - 1) == 1) {
      pawn->legal[r - 1][c - 1] = 1;
    // right
    } else if (getckstate(pawn->team, r - 1, c + 1) == 1) {
      pawn->legal[r - 1][c + 1] = 1;
    }
  } else { // BLACK
    // front
    if (getckstate(pawn->team, r + 1, c) == 0) {
      pawn->legal[r + 1][c] = 1;
    }

    // left
    if (getckstate(pawn->team, r + 1, c - 1) == 1) {
      pawn->legal[r + 1][c - 1] = 1;
    }

    // right
    if (getckstate(pawn->team, r + 1, c + 1) == 1) {
      pawn->legal[r + 1][c + 1] = 1;
    }
  }
}

void knightmv(struct Piece* knight) {
  int r = knight->crds[0];
  int c = knight->crds[1];

  // north 
  if (getckstate(knight->team, r - 2, c - 1) >= 0) {
    knight->legal[r - 2][c - 1] = 1;
  } else if (getckstate(knight->team, r - 2, c + 1) >= 0) {
    knight->legal[r - 2][c + 1] = 1;
  }
}

void rookmv(struct Piece* rook) {
  // north
  for (int r = rook->crds[0] - 1; r >= 0; r--) {
    int c = rook->crds[1];

    if (getckstate(rook->team, r, c) == 1) {
      rook->legal[r][c] = 1;
      break;
    } else if (getckstate(rook->team, r, c) == -1) {
      break;
    } else if (getckstate(rook->team, r, c) == 0) {
      rook->legal[r][c] = 1;
    }
  }

  // west
  for (int c = rook->crds[1] - 1; c >= 0; c--) {
    int r = rook->crds[0];

    if (getckstate(rook->team, r, c) == 1) {
      rook->legal[r][c] = 1;
      break;
    } else if (getckstate(rook->team, r, c) == -1) {
      break;
    } else if (getckstate(rook->team, r, c) == 0) {
      rook->legal[r][c] = 1;
    }
  }
}

void kingmv(struct Piece* king) {
  int r = king->crds[0];
  int c = king->crds[1];

  // clockwise from top-left to middle-left
  if (getckstate(king->team, r - 1, c - 1) >= 0) {
    king->legal[r - 1][c - 1] = 1;
  } else if (getckstate(king->team, r - 1, c) >= 0) {
    king->legal[r - 1][c] = 1;
  } else if (getckstate(king->team, r - 1, c + 1) >= 0) {
    king->legal[r - 1][c + 1] = 1;
  } else if (getckstate(king->team, r, c + 1) >= 0) {
    king->legal[r][c + 1] = 1;
  } else if (getckstate(king->team, r + 1, c + 1) >= 0) {
    king->legal[r + 1][c + 1] = 1;
  } else if (getckstate(king->team, r + 1, c) >= 0) {
    king->legal[r + 1][c] = 1;
  } else if (getckstate(king->team, r + 1, c - 1) >= 0) {
    king->legal[r + 1][c - 1] = 1;
  } else if (getckstate(king->team, r, c - 1) >= 0) {
    king->legal[r][c - 1] = 1;
  }
}

// additionlly, king should not moves to danger zone.
int isdanger(enum Team team, int r, int c) {
  int danger = 0;

  // for WHITE King
  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].team != team) {
      if (pieces[i].legal[r][c] == 1) {
        danger = 1;
      }
    }
  }

  return danger;
}


/* Special Rules */


/* Helper */


// convert user input to crds
void getcrds(char input[2], int *r, int *c) {
  for (int i = 0; i < 8; i++) {
    if (input[1] == rows[i]) *r = i;
  }


  for (int i = 0; i < 8; i++) {
    if (input[0] == cols[i]) *c = i;
  }
}

struct Piece* getpcbycrds(int r, int c) {
  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
      return &pieces[i];
    }
  } 

  return NULL;
};

int getckstate(enum Team team, int r, int c) {
  /*
    -2 error
    ---
    -1 same team
    0 empty
    1 opponent
  */

  // error
  if (r < 0 && r > 7 && c < 0 && c > 7) {
    return -2;
  } 

  int state = 0;
  
  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].crds[0] == r && pieces[i].crds[1] == c) {
      if (pieces[i].team != team) {
        state = 1;
      } else {
        // same team
        state = -1;
      }

      break;
    }
  }

  return state;
}

int isckmate(enum Team team) {
  struct Piece king = team == WHITE ? pieces[0] : pieces[16];
  int r = king.crds[0];
  int c = king.crds[1];

  // 1. Is king in danger zone now?
  for (int i = 0; i < PIECE_CNT; i++) {
    if (pieces[i].team != team) {
      if (pieces[i].legal[r][c] == 1) {
        // yes
        break; 
      }
    }
  }

  // 2. no where to avoid?
  {
    for (int i = 0; i < PIECE_CNT; i++) {
      if (pieces[i].team != team) {
        for (int r = 0; r < 8; r++) {
          for (int c = 0; c < 8; c++) {
            if (pieces[i].legal[r][c] == king.legal[r][c]) {
              king.legal[r][c] = 0;
            }
          }
        }
      }
    }
  }

  // 3. Do removing threat by peers has no effect?
}

int isdrawn() {
  // game count bigger than 100 times
  if (gcount > 100) return 1;

  return 0;
};

/* render */


void printboard() {
  // top space
  printf("\n");

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