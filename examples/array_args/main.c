#include <stdio.h>

void display(int arr[3]) {
  
  for (int i = 0; i < 3; i++)
    printf("%d ", arr[i]);
}

int main(int argc, char const *argv[]) {
  
  int arr[3] = {10, 20, 30};

  display(arr);
}
