#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int main() {

  char vertices[SIZE] = {'A', 'B', 'C', 'D'};

  int adjacencyMatrix[SIZE][SIZE] = {
    {0, 1, 1, 0},
    {0, 0, 0, 0},
    {0, 1, 0, 0},
    {1, 0, 0, 0},
  };

  printf("Connections for each vertex\n");

  for (int r = 0; r < SIZE; r++) {
    printf("%c: ", vertices[r]);

    for (int c = 0; c < SIZE; c++) {
      if (adjacencyMatrix[r][c]) {
        printf("%c ", vertices[c]);
      }
    }
    
    printf("\n");
  }

  // Connection between vertices
  // A: B C D 
  // B: A C 
  // C: A B 
  // D: A 
}
