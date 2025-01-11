#include <stdio.h>

// print only adult
int main() {

  int ages[] = {14, 18, 34};

  for (int i = 0; i < 3; i++) {
    if (ages[i] >= 18) {
      printf("%d\n", ages[i]);
    }
  } 
}