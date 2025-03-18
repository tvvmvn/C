#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 4

char stack[] = "ABCD";
int count = 4;

void pop() {
  if (count < 1) {
    printf("Underflow\n");
  } else {
    count--;
  }
}

void display() {
  for (int i = 0; i < count; i++) {
    printf("%c ", stack[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {

  pop();

  display(); // A B C

  pop();
  pop();
  pop();
  pop(); // Underflow

  return 0;
}