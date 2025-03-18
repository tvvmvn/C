#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASH_SET_SIZE 10

typedef struct Node {
  char* data;
  struct Node* next;
} Node;

Node* myHashSet[HASH_SET_SIZE];

int hashFunction(const char* data) {

  int sum = 0;

  for (int i = 0; data[i] != '\0'; i++) {
    sum += data[i];
  }

  return sum % HASH_SET_SIZE;
}

void add(const char* data) {

  // Get index for adding new node
  int index = hashFunction(data);

  // Creating new node with input data..
  Node* newNode = (Node*)malloc(sizeof(Node));
  
  // Manually allocate memory and copy the string
  // +1 for the null terminator
  newNode->data = (char*)malloc(strlen(data) + 1); 
  strcpy(newNode->data, data);

  newNode->next = NULL;
  
  // No collision, add nodes to buckets
  if (myHashSet[index] == NULL) {
    myHashSet[index] = newNode;
  
  // When collision happens, keep accessing next node 
  } else {
    Node* node = myHashSet[index];

    while (node->next != NULL) {
      node = node->next;
    }

    node->next = newNode;
  }
}

int contains(const char* data) {

  int index = hashFunction(data);

  Node* node = myHashSet[index];

  while (node != NULL) {
    if (strcmp(node->data, data) == 0) {
      return 1; // True
    }
    
    node = node->next;
  }
  
  return 0; // False
}

void freeHashSet() {
  for (int i = 0; i < HASH_SET_SIZE; i++) {
    Node* node = myHashSet[i];

    while (node != NULL) {
      Node* temp = node;
      node = node->next;
      
      // Free the manually allocated string memory
      free(temp->data); 
      free(temp);
    }
  }
}

int main() {
  
  // Add items
  add("Jones");
  add("Lisa");
  add("Bob");
  add("Siri");
  add("Pete");
  add("Stuart");

  // Display buckets
  for (int i = 0; i < HASH_SET_SIZE; i++) {

    printf("Bucket %d: ", i);
    Node* node = myHashSet[i];

    while (node != NULL) {
      printf("%s -> ", node->data);

      node = node->next;
    }

    printf("NULL\n");
  }
  
  // Check whether buckets contain Stuart or not
  printf("\nContains Stuart: %s\n", contains("Stuart") ? "true" : "false");
  
  // Cleanup allocated memory
  freeHashSet(); 
  
  return 0;
}

/*
Bucket 0: NULL
Bucket 1: Jones -> NULL
Bucket 2: NULL
Bucket 3: Lisa -> Stuart -> NULL
Bucket 4: NULL
Bucket 5: Bob -> NULL
Bucket 6: NULL
Bucket 7: Siri -> NULL
Bucket 8: Pete -> NULL
Bucket 9: NULL

Contains Stuart: true
*/