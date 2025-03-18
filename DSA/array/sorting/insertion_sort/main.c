#include <stdio.h>

int main() {

  int arr[] = {8, 5, 6, 2, 4};
  int length = sizeof(arr) / sizeof(arr[0]);

  // rows
  for (int n = 1; n < length; n++) {
    for (int i = 0; i < n; i++) {
      if (arr[i] > arr[n]) {

        int j = i;

        while (j < n) {
          // ..
        }
      }
    }
  }

  // result
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

// Output
// 2 5 6 8 4