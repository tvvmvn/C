/*
  Memory address and pointer

  1 memory address
  2 pointer
  3 array and address
  4 dereference
*/

// 1 memory address
int main() {
  char foo[] = "bar";

  // get the memory address of variable
  printf("%p", foo);
}

// 2 pointer
int main() {
  char foo[] = "bar";
  char *p = foo; // pointer

  printf("%p\n", p);
  printf("%s\n", p);
}

int main() {
  char *p = "abc";

  printf("%p\n", p);
  printf("%s\n", p);
}

// 3 array and address

// address map in char array
int main() {
  char abc[] = "ABC";

  for (int i=0; i<3; i++)
    printf("%p\n", abc + i); 
    // > e.g) a -> b -> c
}

// address map in int array
int main() {
  int gen[] = {10, 20, 30};

  for (int i=0; i<3; i++)
    printf("%p\n", gen + i);
    // > e.g) a -> e -> 2
}

/*
  pointer and struct
*/

struct Piece {
  int id;
  char name[10];
};

int main() {
  struct Piece piece = {1, "pawn"};
  struct Piece* ptr = &piece;

  printf("%s\n", ptr->name); // pawn
}