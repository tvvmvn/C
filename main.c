#include <stdio.h>
#include <stdlib.h>

void print(int &p) {
  printf("%p", p);
};

int main() {
  int n = 89;
  
  print(&n);
}