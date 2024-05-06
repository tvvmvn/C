#include <stdio.h>
#include <stdlib.h>

/*
In summary, when managing memory in C, use best practices:

1 Remember to check for errors (NULL return values) to find out 
if memory allocation was sucessful or not

2 Prevent memory leaks - always remember to free memory that is no longer used, 
or else the program might underperform or even worse, 
crash if it runs out of memory

3 Set the pointer to NULL after freeing memory so that 
you cannot accidentally continue using it
*/

int main() {
  int *ptr;
  
  // If space is insufficient, allocation fails and returns a NULL pointer.
  ptr = malloc(sizeof(*ptr));

  if (ptr == NULL) {
    printf("Unable to allocate memory");

    return 1; // exit
  }

  printf("%p is capable of 4 bytes\n", ptr);

  // free allocated memory
  free(ptr);
  ptr = NULL;

  // set pointer to NULL
  printf("%p", ptr);
}