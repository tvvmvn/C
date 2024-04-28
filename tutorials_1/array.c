#include <stdio.h>
#include <string.h>
#include <math.h>

/*
Array
Data type that have values more than one.
*/


/*
Basic array
*/


int main() {
  char arr[] = {10, 20, 30};

  for (int i = 0; i < sizeof(arr) / 4; i++) {
    printf("%d in %p\n", arr[i], &arr[i]);
  }
}

int main() {
  // not able to change the size of the array after creation.
  int arr[3];

  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;

  for (int i=0; i<sizeof(arr)/4; i++) {
    printf("%d in %p\n", arr[i], &arr[i]);
  }
}


/*
array with pointer  
*/


int main() {
  int* gen;

  *gen = 10; // gen[0] = 10
  *(gen + 1) = 20; // gen[1] = 20
  *(gen + 2) = 30; // gen[2] = 30

  for (int i = 0; i < 3; i++) 
    printf("%d ", gen[i]); // 10 20 30
}


/*
string array
*/


int main() {
  char arr[3][5] = {"foo", "bar", "baz"};

  for (int i = 0; i < 3; i++)
    printf("%s ", arr[i]); // foo bar baz
}


/*
string array with pointer
*/


int main() {
  char* arr[3] = {"foo", "bar", "baz"};

  for (int i = 0; i < 3; i++)
    printf("%s ", arr[i]); // foo bar baz
}


/*
  A function which returns array
*/


int* getArr() {
  int* p;

  *p = 10;
  *(p + 1) = 20;
  *(p + 2) = 30;

  return p;
}

int main() {
  int* arr = getArr();

  printf("%d ", *arr); // 10
  printf("%d ", *(arr + 1)); // 20
  printf("%d ", *(arr + 2)); // 30
}