#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 4

char queue[10];
int head = 0;
int tail = 0;
int count = 0;

void enqueue(char c) {
  if (count < CAPACITY) {
    queue[tail++] = c;
    count++;
  } else {
    printf("Queue is full\n");
  }
}

void display() {
  // display queue
  for (int i = head; i < tail; i++) {
    printf("%c ", queue[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {

  // enqueue 
  enqueue('A');
  enqueue('B');
  enqueue('C');
  enqueue('D');

  display();

  // full
  enqueue('E');

  return 0;
}

// Output
// C D E F G
