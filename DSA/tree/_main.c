#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* left;
  struct Node* right;
};

void preOrderTraverse(struct Node* node) {
  
  if (node == NULL) {
    return;
  }

  printf("%c ", node->data);

  preOrderTraverse(node->left);
  preOrderTraverse(node->right);
};

int main(int argc, char const *argv[]) {

  // creating nodes
  struct Node root;
  root.data = 'R';

  struct Node nodeA;
  nodeA.data = 'A';

  struct Node nodeB;
  nodeB.data = 'B';

  struct Node nodeC;
  nodeC.data = 'C';

  struct Node nodeD;
  nodeD.data = 'D';

  struct Node nodeE;
  nodeE.data = 'E';

  // connecting nodes
  root.left = &nodeA;
  root.right = &nodeB;

  nodeA.left = &nodeC;
  nodeA.right = &nodeD;

  nodeB.left = &nodeE;
  nodeB.right = NULL;

  nodeC.left = NULL;
  nodeC.right = NULL;

  nodeD.left = NULL;
  nodeD.right = NULL;

  nodeE.left = NULL;
  nodeE.right = NULL;

  // traverse tree
  preOrderTraverse(&root);

  return 0;
}

// Output
// R A C D B E
