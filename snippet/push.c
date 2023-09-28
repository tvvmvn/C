#include <stdio.h>
#include <string.h>

// Stack

#define length 5

char arr[length];
int top = -1;

void push(char item) {
  arr[++top] = item;
}

void pop() {
  printf("removed: %c\n", arr[top--]);
}

int main() {
  push('A');
  push('B');
  pop();

  for (int i=0; i<length; i++)
    printf("%c\n", arr[i]);
}



