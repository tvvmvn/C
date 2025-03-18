#include <stdio.h>

int main(int argc, char const *argv[]) {
  
  int arr[] = {10, 20, 30};

  printf("%p\n", arr); // arr is pointer

  printf("%d\n", *arr); // same as arr[0]

  return 0;
}
