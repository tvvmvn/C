#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* left;
  struct Node* right;
};

struct Node createNode(char data) {

  struct Node node;

  node.data = data;
  node.left = NULL;
  node.right = NULL;

  return node;
}

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
  struct Node root = createNode('R');
  struct Node nodeA = createNode('A');
  struct Node nodeB = createNode('B');
  struct Node nodeC = createNode('C');
  struct Node nodeD = createNode('D');
  struct Node nodeE = createNode('E');

  // connecting nodes
  root.left = &nodeA;
  root.right = &nodeB;

  nodeA.left = &nodeC;
  nodeA.right = &nodeD;

  nodeB.left = &nodeE;

  // traverse tree
  preOrderTraverse(&root);

  return 0;
}

// Output
// R A C D B E
