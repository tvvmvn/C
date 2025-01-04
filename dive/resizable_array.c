#include <stdio.h>
#include <stdlib.h>

struct List {
  // Points to the memory where the List items are stored
  char* values; 
  // Indicates how many items are currently in the List
  int size; 
  // Indicates how many items fit in the allocated memory
  int max; 
};

// This function adds an item to a List
void add(struct List *myList, char item) {

  // If list is full, resize the memory to take one more item.
  if (myList->size == myList->max) {
    myList->max++;

    myList->values = realloc(myList->values, myList->max * sizeof(char));
  }

  // Add the item to the end of list
  myList->values[myList->size] = item;
  myList->size++;
}

int main() {

  struct List myList;

  myList.size = 0;
  myList.max = 1;
  myList.values = malloc(myList.max * sizeof(char));

  // Find out if memory allocation was successful
  if (myList.values == NULL) {
    printf("Memory allocation failed");

    // Exit the program with an error code
    return 1; 
  }
  
  // You can add items as many as you want
  add(&myList, 'e');
  add(&myList, 'e');
  add(&myList, 'e');
  add(&myList, 'e');

  // Display list
  printf("{");
  for (int i = 0; i < myList.size; i++) {
    printf("%c,", myList.values[i]);
  }
  printf("}");

  // Free the memory when it is no longer needed
  free(myList.values);

  myList.values = NULL;

  return 0;
}