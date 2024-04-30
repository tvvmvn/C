#include <stdio.h>
#include <stdlib.h>


char stack[5];
int top = 0;

void push(char c) {
  if (top < 5)
    stack[top++] = c;
  else
    printf("overflow\n");
}

void pop() {
  if (top > 0)
    --top;
  else
    printf("underflow\n");
}

int main() {
  push('A');
  push('B');
  push('C');
  push('D');
  push('E');
  pop();
  push('F');

  for (int j = 0; j < top; j++)
    printf("%c ", stack[j]); // A B C D F 
}