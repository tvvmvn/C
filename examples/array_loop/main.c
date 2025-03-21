#include <stdio.h>

int main(int argc, char const *argv[]) {

  int arr[] = {10, 20, 30};
  int length = sizeof(arr) / sizeof(arr[0]);

  for (int i = 0; i < length; i++) 
    printf("%d\n", arr[i]);

  return 0;
}

