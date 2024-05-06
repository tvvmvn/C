#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char value;
  // address of child node
  struct Node* left;
  struct Node* right;
} Node;

Node createNode(char value) {
  Node node;
  node.value = value;

  return node;
}

int main() {
  // create nodes
  Node root = createNode('R');
  Node nodeA = createNode('A');
  Node nodeB = createNode('B');
  Node nodeC = createNode('C');

  // connect nodes
  root.left = &nodeA;
  root.right = &nodeB;
  
  nodeA.left = &nodeC;

  // access nodes
  printf("%c\n", root.value); // R
  printf("%c\n", root.left->value); // A
  printf("%c\n", root.right->value); // B
  printf("%c\n", root.left->left->value); // C
}