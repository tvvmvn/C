#include <stdio.h>

int main(int argc, char const *argv[]) {
  
  int arr[] = {10, 20, 30};

  int length = sizeof(arr) / sizeof(arr[0]);

  printf("%d\n", length);
}
