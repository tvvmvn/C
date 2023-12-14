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
  char store[] = "ㄱㄴㄷㄹㅁㅂㅅㅇㅈㅊㅋㅌㅍㅎ"; // 14 characters
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  char c;
  int i = 1;

  srand(time(NULL));

  printf("# CHOSUNG GAME\n");

  while (i < 10) {
    i1 = rd_index();
    i2 = i1 + 1;
    i3 = i1 + 2;
    i4 = rd_index();
    i5 = i4 + 1;
    i6 = i4 + 2;

    printf("%d. ", i);
    printf("%c%c%c", store[i1], store[i2], store[i3]);
    printf("%c%c%c\n", store[i4], store[i5], store[i6]);
    printf("press enter to pass >>");

    c = getchar();

    if (c != '\n') {
      break;
    }

    i++;
  }
}


