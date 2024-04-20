/*
C program to create dynamic array using malloc() function

Array in C is static in nature, so its size should be known at compile time 
and we can’t change the size of the array after its declaration. 

Due to this, we may encounter situations where our array doesn’t have 
enough space left for required elements or we allotted more than 
the required memory leading to memory wastage. 
To solve this problem, dynamic arrays come into the picture.

A Dynamic Array is allocated memory at runtime 
and its size can be changed later in the program.
*/

#include <stdio.h>
#include <stdlib.h>


int main() {

  // address of the block created hold by this pointer
  int *ptr;
  int size;

  // Size of the array
  printf("Enter size of elements:");
  scanf("%d", &size);

  //  Memory allocates dynamically using malloc()
  ptr = (int *)malloc(size * sizeof(int));

  // Checking for memory allocation
  if (ptr == NULL) {
    printf("Memory not allocated.\n");
  } else {
    // Memory allocated
    printf("Memory successfully allocated using malloc.\n");

    // Get the elements of the array
    for (int j = 0; j < size; ++j) {
      ptr[j] = (j + 1) * 10;
    }

    // Print the elements of the array
    printf("The elements of the array are: ");
    
    for (int k = 0; k < size; ++k) {
      printf("%d, ", ptr[k]);
    }
  }

  return 0;
}