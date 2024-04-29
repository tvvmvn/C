#include <stdio.h>
#include <stdlib.h>

// linked list
typedef struct Node {
  int value;
  struct Node* next;
} Node;

int main() {
  Node node4;
  node4.value = 40;
  node4.next = NULL;

  Node node3;
  node3.value = 30;
  node3.next = &node4;

  Node node2;
  node2.value = 20;
  node2.next = &node3;

  Node node1;
  node1.value = 10;
  node1.next = &node2;

  printf("%d", node1.next->next->next->value); // 40
}