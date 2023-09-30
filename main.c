#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char pick;
  char board[] = {
    '1', '2', '3', 
    '4', '5', '6', 
    '7', '8', '9', 
    '\0'
  };

  while (1) {
    printf("choose 1 to 9\n");

    if (pick != '\n') {
      printf("=====\n");
      printf("%c %c %c\n", board[0], board[1], board[2]);
      printf("%c %c %c\n", board[3], board[4], board[5]);
      printf("%c %c %c\n", board[6], board[7], board[8]);
      printf("=====\n");
    }

    pick = getchar();

    if (pick != '\n') {
      for (int i=0; i<strlen(board); i++) {
        if (board[i] == pick) {
          board[i] = 'X';
          break;
        }
      }
    }
  }
}
