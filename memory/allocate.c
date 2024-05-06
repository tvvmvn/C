#include <stdio.h>
#include <stdlib.h>

/*
The malloc() and calloc() functions allocate some memory and 
return a pointer to its address.
If space is insufficient, allocation fails and returns a NULL pointer.


# (cast-type*)malloc(size)
size: specifies how much memory to allocate, measured in bytes.


# (cast-type*)calloc(amount, size)
amount: Specifies the amount of items to allocate
size: Specifies the size of each item measured in bytes

The data in the memory allocated by malloc() is unpredictable. 
To avoid unexpected values, make sure to write something into the memory 
before reading it.

Unlike malloc(), the calloc() function writes zeroes into all of the allocated memory. 
However, this makes calloc() slightly less efficient.
*/
