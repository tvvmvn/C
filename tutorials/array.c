#include <stdio.h>
#include <string.h>
#include <math.h>

/*
  Array
  Data type that have values more than one.

  1 Basic
  2 String array
*/


/*
  Basic array
*/

int main() {
  char arr[] = {10, 20, 30};

  for (int i=0; i<sizeof(arr)/4; i++) {
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
  String array
*/

int main() {
  char arr[3][5] = {"foo", "bar", "baz"};

  for (int i=0; i<3; i++) {
    printf("%s in %p\n", arr[i], arr[i]);
  }
}

/*
  push and pop

  Stack
*/

#define length 5

char arr[length];
int top = -1;

void push(char item) {
  arr[++top] = item;
}

void pop() {
  printf("removed: %c\n", arr[top--]);
}

int main() {
  push('A');
  push('B');
  pop();

  for (int i=0; i<length; i++)
    printf("%c\n", arr[i]);
}