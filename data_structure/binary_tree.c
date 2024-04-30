#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char value;
  struct Node* left;
  struct Node* right;
} Node;

int main() {
  Node root;
  root.value = 'R';

  Node nodeA;
  nodeA.value = 'A';

  Node nodeB;
  nodeB.value = 'B';

  Node nodeC;
  nodeC.value = 'C';

  Node nodeD;
  nodeD.value = 'D';

  Node nodeE;
  nodeE.value = 'E';

  // connect
  root.left = &nodeA;
  root.right = &nodeB;

  nodeA.left = &nodeC;
  nodeA.right = &nodeD;

  nodeB.left = &nodeE;
  nodeB.right = NULL;
}