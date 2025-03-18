#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_COUNT 10
// Define a maximum string length
#define MAX_STRING_LENGTH 256 

typedef struct Node {
  // Use a fixed-size array for values
  char data[MAX_STRING_LENGTH]; 
  struct Node* next;
} Node;

typedef struct {
  Node* buckets[BUCKET_COUNT];
} SimpleHashSet;

unsigned int hashFunction(const char* data) {
  unsigned int hash = 0;

  while (*data) {
    hash = (hash + *data++) % BUCKET_COUNT;
  }

  return hash;
}

void initHashSet(SimpleHashSet* set) {
  for (int i = 0; i < BUCKET_COUNT; i++) {
    set->buckets[i] = NULL;
  }
}

int contains(SimpleHashSet *set, const char *data) {
  unsigned int index = hashFunction(data);

  Node *node = set->buckets[index];

  while (node != NULL) {
    if (strcmp(node->data, data) == 0) {
      return 1; // Found
    }

    node = node->next;
  }

  return 0; // Not found
}


void add(SimpleHashSet* set, const char* data) {
  unsigned int index = hashFunction(data);
  
  // Check if the data already exists to avoid duplicates
  Node* current = set->buckets[index];

  while (current != NULL) {
    if (strcmp(current->data, data) == 0) {
      // Value already exists, do not add again
      return;
    }

    current = current->next;
  }
  
  // Add new data
  Node* newNode = (Node*)malloc(sizeof(Node));

  if (!newNode) return; // Handle malloc failure
  
  strncpy(newNode->data, data, MAX_STRING_LENGTH);
  newNode->data[MAX_STRING_LENGTH - 1] = '\0'; // Ensure null-termination
  newNode->next = set->buckets[index];

  set->buckets[index] = newNode;
}

void removeValue(SimpleHashSet *set, const char *data) {

  unsigned int index = hashFunction(data);

  Node **node = &(set->buckets[index]);

  while (*node != NULL) {
    if (strcmp((*node)->data, data) == 0) {
      Node *toDelete = *node;
      *node = (*node)->next;
      free(toDelete); // Just free the node, not toDelete->data
      
      return; // Value removed
    }

    node = &((*node)->next);
  }
}

void printHashSet(SimpleHashSet *set) {
  printf("Hash Set Contents:\n");

  for (int i = 0; i < BUCKET_COUNT; i++) {
    Node *node = set->buckets[i];
    printf("Bucket %d: ", i);

    while (node) {
      printf("%s ", node->data);
      node = node->next;
    }

    printf("\n");
  }
}

int main() {

  // creating HashSet
  SimpleHashSet hashSet;
  initHashSet(&hashSet);

  // add items to buckets
  add(&hashSet, "Charlotte");
  add(&hashSet, "Thomas");
  add(&hashSet, "Jens");
  add(&hashSet, "Peter");
  add(&hashSet, "Lisa");
  add(&hashSet, "Adele");
  add(&hashSet, "Michaela");
  add(&hashSet, "Bob");

  // display HashSet
  printHashSet(&hashSet);

  // Check whether Peter is in the set or not
  printf("\n'Peter' is in the set: %s\n", contains(&hashSet, "Peter") ? "true" : "false");
  
  // Test for cleaning up buckets
  printf("Removing 'Peter'\n");
  removeValue(&hashSet, "Peter");
  printf("'Peter' is in the set: %s\n", contains(&hashSet, "Peter") ? "true" : "false");

  // Get hash code of items
  printf("'Adele' has hash code: %u\n", hashFunction("Adele"));

  // Free memory, omitted for brevity
  return 0;
}

/*
Hash Set Contents:

Bucket 0: Jens Thomas
Bucket 1:
Bucket 2: Peter
Bucket 3: Lisa
Bucket 4: Charlotte
Bucket 5: Bob Adele
Bucket 6:
Bucket 7:
Bucket 8: Michaela
Bucket 9:

'Peter' is in the set: true

Removing 'Peter'
'Peter' is in the set: false

'Adele' has hash code: 5
*/