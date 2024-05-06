#include <stdio.h>
#include <stdlib.h>

/*
C program to implement delete operation in an unsorted array
*/

int findElement(int arr[], int n, int key) {
  int i;

  for (i = 0; i < n; i++) {
    if (arr[i] == key) {
      return i;
    }
  }

  return -1;
}

int deleteElement(int arr[], int n, int key) {
  int pos = findElement(arr, n, key); 

  if (pos == -1) {
    printf("Element not found");

    return n;
  }

  int i;

  for (i = pos; i < n - 1; i++) { // i = 2; i < 4; i++
    arr[i] = arr[i + 1];
  }

  return n - 1; // 4
}

int main() {
  int i;
  int arr[] = {10, 50, 30, 40, 20};

  int n = sizeof(arr) / sizeof(arr[0]); // 5
  int key = 30;

  printf("Array before deletion\n");
  for (i = 0; i < n; i++) {
    printf("%d  ", arr[i]); // 10 50 30 40 20
  }

  n = deleteElement(arr, n, key);

  printf("\nArray after deletion\n");
  for (i = 0; i < n; i++) {
    printf("%d  ", arr[i]); // 10 50 40 20
  }

  // A hole at last position (should be freed)
  printf("\nA hole info\n");
  int* ptr = arr + (n - 1);
  printf("%p\n", ptr);
  printf("%d\n", *ptr); // 20

  return 0;
}