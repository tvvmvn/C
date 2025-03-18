#include <stdio.h>

int main() {

  int arr[] = {8, 5, 6, 2, 4};
  int length = sizeof(arr) / sizeof(arr[0]);

  // rows
  for (int n = 1; n < length; n++) {
    
    // columns
    int selectedIndex = n;
    int selectedItem = arr[n];
    int j = n - 1;

    while (j >= 0 && arr[j] > selectedItem) {
      arr[j + 1] = arr[j];
      selectedIndex = j;
      j--;
    }
    
    arr[selectedIndex] = selectedItem;
  }

  // result
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}

// Output
// 2 5 6 8 4