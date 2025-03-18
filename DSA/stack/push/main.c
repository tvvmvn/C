#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 4

char stack[CAPACITY];
int count = 0;

void push(char c) {
  if (count < CAPACITY) {
    stack[count++] = c;
  } else {
    printf("Overflow\n");
  }
}

void display() {
  for (int i = 0; i < count; i++) {
    printf("%c ", stack[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {

  push('A');
  push('B');
  push('C');  
  push('D');

  display(); // A B C D

  push('D'); // Overflow

  return 0;
}