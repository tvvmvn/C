#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* next;
};

struct Node createNode(char data) {

  struct Node node;

  node.data = data;
  node.next = NULL;

  return node;
} 

int main(int argc, char const *argv[]) {

  // creating nodes
  struct Node node1 = createNode('A');
  struct Node node2 = createNode('B');
  struct Node node3 = createNode('C');

  // connecting nodes
  node1.next = &node2;
  node2.next = &node3;
  node3.next = NULL;

  // display list
  struct Node* currentNode = &node1;

  while (currentNode) {
    printf("%c -> ", currentNode->data);

    currentNode = currentNode->next;
  }
  printf("null\n");

  return 0;
}

// Output
// A -> B -> C -> null