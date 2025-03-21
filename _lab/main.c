#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  char data;
} Node;

int main(int argc, char const *argv[]) {

  printf("%lu\n", sizeof(Node)); // 1

  // Node* ptr = malloc(sizeof(Node));
}


