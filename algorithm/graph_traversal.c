#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

/*
DFS (Depth First Search) Traversal
*/

void dfsUtil(char vertices[SIZE], int adjacencyMatrix[SIZE][SIZE], int index, int visited[]) {
  // update visit to 1
  visited[index] = 1;
  
  printf("%c ", vertices[index]);

  for (int i = 0; i < SIZE; i++) {
    if (adjacencyMatrix[index][i] == 1 && !visited[i]) {
      dfsUtil(vertices, adjacencyMatrix, i, visited);
    }
  }
}

int main() {
  char vertices[SIZE] = {'A', 'B', 'C', 'D'};
  int adjacencyMatrix[SIZE][SIZE] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 0},
    {1, 0, 0, 0},
  };
  // A: B C D
  // B: A C
  // C: A B
  // D: A


  // DFS start
  int visited[SIZE] = {0};
  char startVertex = 'D';
  int index = -1;

  for (int i = 0; i < SIZE; i++) {
    if (vertices[i] == startVertex) {
      index = i; // 3
      break;
    }
  }

  printf("DFS starting from vertex D: ");
  dfsUtil(vertices, adjacencyMatrix, index, visited); 
  // D A B C
}