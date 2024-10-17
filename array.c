#include <stdio.h>

int main() {
  // print only adult

  int ages[] = {14, 18, 34};

  for (int i = 0; i < 3; i++) {
    if (ages[i] >= 18) {
      printf("%d\n", ages[i]);
    }
  } 
}