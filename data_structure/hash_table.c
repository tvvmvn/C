#include <stdio.h>
#include <stdlib.h>

/*
hash table
collision is not covered
*/

const int size = 10;
int buckets[size];

int hashf(char* key) {
  int sum = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    sum += key[i];
  }

  return sum % size;
}

void add(char* key, int item) {
  int hash = hashf(key);

  buckets[hash] = item;
};

int search(char* key) {
  int hash = hashf(key);

  int value = buckets[hash];

  return value;
}

int main() {
  // add
  add("Ray", 2000);
  add("Avante", 2500);
  add("XM3", 3000);


  // looping buckets
  // for (int i = 0; i < size; i++)
  //   printf("%d\n", buckets[i]);


  // search
  int value = search("Ray");

  printf("Ray: %d", value); // Ray: 2000
}
