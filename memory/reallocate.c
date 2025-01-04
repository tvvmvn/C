#include <stdio.h>
#include <stdlib.h>

int main() {

  int *ptr1, *ptr2;

  // Allocating 4 bytes of memory to ptr1.
  ptr1 = malloc(4);

  // Reallocating 8 bytes of memory to pointer.
  ptr2 = realloc(ptr1, 8);

  // error checking for reallocating memory
  if (ptr2 == NULL) {
    
    // reallocation fails
    printf("Unable to resize memory.");
    
    // Exit the program with an error code
    return 1; 
  } 
  
  // If reallocation is sucessful
  printf("Success. 8 bytes are reallocated at address %p \n", ptr2);

  // Update ptr1 to point to the newly allocated memory
  ptr1 = ptr2; 
 
  return 0;
}