#include <stdio.h>
#include <stdlib.h>

// linked list
typedef struct Node {
  int value;
  // address of next node
  struct Node* next;
} Node;

Node createNode(int value) {
  Node node;
  node.value = value;

  return node;
}

void printList(struct Node* node) {
  while (node) {
    printf("%d -> ", node->value);
    node = node->next;
  }
  
  printf("null\n");
}

int main() {
  // create nodes
  Node node1 = createNode(10);
  Node node2 = createNode(20);
  Node node3 = createNode(30);
  Node node4 = createNode(40);

  // connect nodes
  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = NULL;

  // access nodes
  printList(&node1);

  // free the memory
  // free(node1);
  // free(node2);
  // free(node3);
  // free(node4);
}