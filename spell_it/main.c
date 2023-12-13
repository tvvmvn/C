#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

/*
  fgets(myString, 100, fptr);

  The first parameter specifies where to store the file content,
  which will be in the myString array we just created.

  The second parameter specifies the maximum size of data to read, 
  which should match the size of myString (100).

  The third parameter requires a file pointer that is used to read the file 
  (fptr in our example).
*/

int main() {
  int index = 0;
  int pass;
  char user[100];

  char list[3][100] = {
    "hello c\n", 
    "hello cpp\n", 
    "hello js\n"
  };

  while (index < 3) {
    printf("--- Type this word: \n");
    printf("%s\n", list[index]);

    fgets(user, sizeof(user), stdin);

    pass = strcmp(list[index], user);
  
    if (pass == 0) {
      printf("well done\n");
      index++;
    } else {
      printf("mispelled!\n");
    }
  }

  printf("YOU WIN!\n");
}