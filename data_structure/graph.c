#include <stdio.h>
#include <stdlib.h>

int main() {
  char vertexData[4] = {'A', 'B', 'C', 'D'};

  int adjacencyMatrix[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
  };

  printf("Connections for each vertex\n");

  for (int r = 0; r < 4; r++) {
    printf("%c: ", vertexData[r]);
    for (int c = 0; c < 4; c++) {
      if (adjacencyMatrix[r][c]) {
        printf("%c ", vertexData[c]);
      }
    }
    printf("\n");
  }

  // Connections for each vertex
  // A: B C D 
  // B: A C 
  // C: A B 
  // D: A 
}
