#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr1, *ptr2;

  // Allocate memory
  ptr1 = malloc(4);

  // Attempt to resize the memory
  ptr2 = realloc(ptr1, 8);

  // Check whether realloc is able to resize the memory or not
  if (ptr2 == NULL) {
    // If reallocation fails
    printf("Failed. Unable to resize memory");
  } else {
    // If reallocation is sucessful
    printf("Success. 8 bytes reallocated at address %p \n", ptr2);
    ptr1 = ptr2; // Update ptr1 to point to the newly allocated memory
  }
 
  return 0;
}