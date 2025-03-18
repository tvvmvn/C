#include <stdio.h>
#include <stdlib.h>

int main() {

  int *ptr;

  // Allocate memory for an integer (4 bytes)
  ptr = malloc(sizeof(*ptr)); 

  // error checking for allocating memory
  if (ptr == NULL) {
    printf("Unable to allocate memory");
    
    // end the main() function
    return 1;
  }

  // Set the value of the integer
  *ptr = 20;
  
  printf("Integer value: %d\n", *ptr);

  // Free allocated memory
  free(ptr);

  // Set the pointer to NULL to prevent it from being accidentally used
  ptr = NULL; 
  
  return 0;
}