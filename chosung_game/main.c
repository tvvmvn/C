#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int rd_index() {
  int x;
  
  while(1) {
    x = (rand() % 40);

    if (x % 3 == 0) { 
      break;
    } 
  }

  return x;
}

int main() {
  // 14 Korean alphabets (3 byte)
  char store[] = "ㄱㄴㄷㄹㅁㅂㅅㅇㅈㅊㅋㅌㅍㅎ"; 
  int i1;
  int i2;
  char c;
  int i = 1;

  srand(time(NULL));

  printf("# CHOSUNG GAME\n");

  while (i < 10) {
    i1 = rd_index();
    i2 = rd_index();

    printf("%d. ", i);
    printf("%c%c%c", store[i1], store[i1 + 1], store[i1 + 2]);
    printf("%c%c%c\n", store[i2], store[i2 + 1], store[i2 + 2]);
    printf("press enter to next >>");

    c = getchar();

    if (c != '\n') {
      break;
    }

    i++;
  }
}


