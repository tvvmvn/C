#include <stdio.h>
#include <string.h>

/*
  Condition

  1 if/else
  2 switch
*/

int main() {
  switch (2023) {
    case 2022:
      printf("Last year");
      break;

    case 2023:
      printf("This year");
      break;

    case 2024:
      printf("Next year");
      break;
    
    default:
      printf("Not a close year");
  }
}