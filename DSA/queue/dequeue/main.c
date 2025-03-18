#include <stdio.h>
#include <stdbool.h>

char queue[] = {'A', 'B', 'C', 'D', '\0'};
int head = 0;
int tail = 4;
int count = 4;

void dequeue() {
  if (count < 1) {
    printf("Queue is empty\n");
  } else {
    head++;
    count--;
  }
}

void display() {
  for (int i = head; i < tail; i++) {
    printf("%c ", queue[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]) {

  dequeue();
  dequeue();
  dequeue();

  display(); // D
  
  dequeue();
  dequeue(); // Queue is empty

  return 0;
}
