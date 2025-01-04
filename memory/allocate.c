#include <stdio.h>
#include <stdlib.h>

int main() {

  int *ptr;

  // Allocate memory
  ptr = malloc(4);

  // Find out if memory allocation was successful
  if (ptr == NULL) {
    printf("Memory allocation failed");
    
    return 1; // Exit the program with an error code
  } 

  // If allocation is sucessful
  printf("Success. 4 bytes allocated at address %p \n", ptr);
 
  return 0;
}