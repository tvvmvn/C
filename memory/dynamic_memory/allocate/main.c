#include <stdio.h>
#include <stdlib.h>

int main() {

  char* ptr;

  // Allocate 4 bytes of space to pointer
  ptr = calloc(4, sizeof(*ptr));

  // Find out if memory allocation was successful
  if (ptr == NULL) {
    printf("Memory allocation failed");
    
    return 1; // Exit the program with an error code
  } 

  // If allocation is sucessful
  printf("address of ptr: %p \n", ptr);
  printf("size of allocated space: %lu bytes\n", sizeof(*ptr));
 
  return 0;
}
