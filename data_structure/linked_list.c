#include <stdio.h>
#include <stdlib.h>

// linked list
typedef struct Node {
  int value;
  struct Node* next;
} Node;

void printList(struct Node* node) {
  while (node) {
    printf("%d -> ", node->value);
    node = node->next;
  }
  printf("null\n");
}

int main() {
  Node node1;
  node1.value = 10;

  Node node2;
  node2.value = 20;

  Node node3;
  node3.value = 30;

  Node node4;
  node4.value = 40;

  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;
  node4.next = NULL;

  printList(&node1);

  // free the memory
  // free(node1);
  // free(node2);
  // free(node3);
  // free(node4);
}