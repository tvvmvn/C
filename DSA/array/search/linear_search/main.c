#include <stdio.h>

int linearSearch(int arr[], int length, int target) {
  
  for (int i = 0; i < length; i++) {
    if (arr[i] == target) {
      return i;
    }
  }

  return -1;
}

int main() {
  int arr[] = {3, 7, 2, 9, 5};
  int target = 9;
  int length = sizeof(arr) / sizeof(arr[0]);

  int result = linearSearch(arr, length, target);

  if (result != -1) {
    printf("%d found at index %d\n", target, result);
  } else {
    printf("Value %d not found\n", target);
  }

  return 0;
}



// 9 found at index 3