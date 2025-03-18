#include <stdio.h>

int main() {
  int arr[] = {64, 34, 25, 5, 22, 11, 90, 12};
  int n = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < n - 1; i++) {
    int min_index = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_index]) {
        min_index = j;
      }
    }

    int min_value = arr[min_index];

    for (int k = min_index; k > i; k--) {
      arr[k] = arr[k - 1];
    }
    
    arr[i] = min_value;
  }

  printf("Sorted: ");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}


// Sorted: 5 11 12 22 25 34 64 90