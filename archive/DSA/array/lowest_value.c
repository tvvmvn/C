#include <stdio.h>

int main() {
  
  int arr[] = {7, 12, 9, 4, 11};
  int length = sizeof(arr) / sizeof(arr[0]);
  int minVal = arr[0];

  for (int i = 0; i < length; i++) {
    if (arr[i] < minVal) {
      minVal = arr[i];
    }
  }

  printf("Lowest value: %d\n", minVal);
  
  return 0;
}

// Output
// Lowest value: 4