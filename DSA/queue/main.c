#include <stdio.h>
#include <stdbool.h>

#define m 10 // memory space (global variables)

int queue[m];
int front = 0;
int size = 0;
int capacity = 5;

void enqueue(char c) {
  if (size < capacity) {
    queue[front + size] = c;
    ++size;
  } else {
    printf("Queue is full\n");
  }
}

void dequeue() {
  if (size < 1) {
    printf("Queue is empty\n");
  } else {
    ++front;
    --size;
  }
}

int main(int argc, char const *argv[]) {

  // enqueue and dequeue
  enqueue('A');
  enqueue('B');
  enqueue('C');
  enqueue('D');
  enqueue('E');
  dequeue();
  dequeue();
  enqueue('F');
  enqueue('G');
  
  // display queue
  for (int i = front; i < front + size; i++)
    printf("%c ", queue[i]);

  return 0;
}

// Output
// C D E F G
