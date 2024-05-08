#include <stdio.h>
#include <stdlib.h>

// pre-order traversal

typedef struct Node {
  char value;
  struct Node* left;
  struct Node* right;
} Node;

Node* createNewNode(char value) {
  Node *node = malloc(sizeof(Node));

  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void preOrderTraversal(Node* root) {
  if (root != NULL) {
    printf("%c ", root->value);

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
  }
}

int main() {
  // create nodes
  Node* root = createNewNode('R');
  Node* nodeA = createNewNode('A');
  Node* nodeB = createNewNode('B');
  Node* nodeC = createNewNode('C');
  Node* nodeD = createNewNode('D');
  Node* nodeE = createNewNode('E');
  Node* nodeF = createNewNode('F');
  Node* nodeG = createNewNode('G');

  // connect nodes
  root->left = nodeA;
  root->right = nodeB;

  nodeA->left = nodeC;
  nodeA->right = nodeD;

  nodeB->left = nodeE;
  nodeB->right = nodeF;

  nodeF->left = nodeG;

  // traverse tree
  preOrderTraversal(root);
}