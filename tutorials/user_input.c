#include <stdio.h>
#include <string.h>

/*
  User input

  scanf(format specifier, reference operator)

  * reference operator
  stores the memory address of the variable.
*/


// basic
int main() {
  char name[10];

  printf("What is your name?");

  scanf("%s", name);

  printf("Hi, %s!", name);
}


// multiple inputs
int main() {
  char fname[10];
  char lname[10];

  // Name
  printf("What is your first name and last name?\n");
  scanf("%s %s", fname, lname);

  printf("Hi, %s %s\n!", fname, lname);
}

// get multiple words
int main() {
  char name[50];

  printf("What is your name?\n");

  // use fgets() for multiple words.
  fgets(name, sizeof(name), stdin);

  printf("Hi, %s", name);
}

// validation
int main() {
  int num;

  printf("Enter a number\n");

  while (scanf("%d", &num) != 1) {
    printf("Not a number. Enter again\n");
    // *(asterisk) tells scanf to read and ignore the value
    scanf("%*s");
  }

  printf("number: %d\n", num);
}