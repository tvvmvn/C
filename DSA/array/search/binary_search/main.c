#include <stdio.h>

int binarySearch(int arr[], int length, int target) {
  
  int first = 0;
  int last = length - 1;

  while (first <= last) {

    int mid = (first + last) / 2;

    if (arr[mid] == target) {
      return mid;
    }

    if (arr[mid] < target) {
      first = mid + 1;
    } else {
      last = mid - 1;
    }
  }

  return -1;
}

int main() {

  int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  int target = 15;
  int length = sizeof(arr) / sizeof(arr[0]);

  int result = binarySearch(arr, length, target);

  if (result != -1) {
    printf("%d found at index %d\n", target, result);
  } else {
    printf("Target not found in array.\n");
  }

  return 0;
}

// Output
// 15 found at index 7