

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