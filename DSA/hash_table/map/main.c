#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_COUNT 10
#define MAX_KEY_LEN 16
#define MAX_VAL_LEN 32

typedef struct Entry {
  char key[MAX_KEY_LEN];
  char value[MAX_VAL_LEN];
  struct Entry* next;
} Entry;

typedef struct {
  Entry* buckets[BUCKET_COUNT];
} SimpleHashMap;

void initHashMap(SimpleHashMap* map) {
  for (int i = 0; i < BUCKET_COUNT; i++) {
    map->buckets[i] = NULL;
  }
}

unsigned int hashFunction(const char* key) {
  unsigned int sum = 0;
  
  for (int i = 0; key[i] != '\0'; i++) {
    if (key[i] >= '0' && key[i] <= '9') {
      sum += key[i] - '0';
    }
  }

  return sum % BUCKET_COUNT;
}

void put(SimpleHashMap* map, const char* key, const char* value) {

  unsigned int index = hashFunction(key);

  Entry* node = map->buckets[index];
  
  // address is already occupied
  while (node != NULL) { // checking all entries connected with input key
    
    // Update value if entry with input key already exists
    if (strcmp(node->key, key) == 0) {
      // set new value
      strncpy(node->value, value, MAX_VAL_LEN - 1);
      node->value[MAX_VAL_LEN - 1] = '\0'; // terminator

      return;
    }

    node = node->next;
  }
  
  // Add a new entry
  Entry* newEntry = (Entry*)malloc(sizeof(Entry));

  // Set key and value
  strncpy(newEntry->key, key, MAX_KEY_LEN - 1);
  newEntry->key[MAX_KEY_LEN - 1] = '\0'; // string terminator
  strncpy(newEntry->value, value, MAX_VAL_LEN - 1);
  newEntry->value[MAX_VAL_LEN - 1] = '\0'; // string terminator

  newEntry->next = map->buckets[index]; // NULL or not

  map->buckets[index] = newEntry; // push entry if occupied
}

const char* get(SimpleHashMap* map, const char* key) {

  unsigned int index = hashFunction(key);
  Entry* node = map->buckets[index];
  
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      return node->value;
    }
    
    node = node->next;
  }
  
  return NULL; // Key not found
}

void removeEntry(SimpleHashMap* map, const char* key) {
  
  unsigned int index = hashFunction(key);
  Entry* node = map->buckets[index];
  Entry* prev = NULL;
  
  while (node != NULL) {
    if (strcmp(node->key, key) == 0) {
      if (prev != NULL) {
        prev->next = node->next;
      } else {
        map->buckets[index] = node->next;
      }

      free(node);
      return;
    }

    prev = node;
    node = node->next;
  }
}

void freeHashMap(SimpleHashMap* map) {
  for (int i = 0; i < BUCKET_COUNT; i++) {
    Entry* node = map->buckets[i];

    while (node != NULL) {
      Entry* temp = node;
      node = node->next;
      free(temp);
    }
  }
}

void printHashMap(SimpleHashMap* map) {

  printf("Hash Map Contents:\n");

  for (int i = 0; i < BUCKET_COUNT; i++) {
    Entry* node = map->buckets[i];
    printf("Bucket %d: ", i);

    while (node != NULL) {
      printf("(%s: %s) ", node->key, node->value);
      node = node->next;
    }

    printf("\n");
  }
}

int main() {

  // Creating hash map
  SimpleHashMap map;
  initHashMap(&map);

  // Add entries (each key is unique) to hash map
  put(&map, "123-4567", "Charlotte");
  put(&map, "123-4568", "Thomas");
  put(&map, "123-4569", "Jens");
  put(&map, "123-4570", "Peter");
  put(&map, "123-4571", "Lisa");
  put(&map, "123-4672", "Adele");
  put(&map, "123-4573", "Michaela");
  put(&map, "123-6574", "Bob");

  // Display hash map
  printHashMap(&map);
  printf("\n");

  // Get name with key 123-4570
  printf("Name with key 123-4570: %s\n", get(&map, "123-4570"));

  // Update name of entries with key 123-4570 to James
  put(&map, "123-4570", "James\n");
  printf("Name with key 123-4570: %s\n", get(&map, "123-4570"));

  // free
  freeHashMap(&map);

  return 0;
}


/*
Hash Map Contents:

Bucket 0: (123-4569: Jens)
Bucket 1:
Bucket 2: (123-4570: Peter)
Bucket 3: (123-4571: Lisa)
Bucket 4:
Bucket 5: (123-4573: Michaela) (123-4672: Adele)
Bucket 6:
Bucket 7:
Bucket 8: (123-6574: Bob) (123-4567: Charlotte)
Bucket 9: (123-4568: Thomas)

Name with key 123-4570: Peter

Name with key 123-4570: James
*/