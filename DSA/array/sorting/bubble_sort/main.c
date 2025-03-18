#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int arr[] = {5, 3, 1, 4, 2};
  int length = sizeof(arr) / sizeof(arr[0]);

  // n: rows
  for (int n = 1; n < length; n++) { 
    // i: items index
    for (int i = 0; i < length - n; i++) { 
      
      if (arr[i] > arr[i + 1]) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
      }
    }
  }

  for (int i = 0; i < length; i++)
    printf("%d ", arr[i]);

  return 0;
}
