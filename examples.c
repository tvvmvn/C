#include <stdio.h>
#include <string.h>
#include <math.h>

/*
  Loop
*/

// print adult age
int main() {
  int ages[4] = {10, 20, 30, 40};

  for (int i=0; i<4; i++) {
    if (ages[i] >= 18) 
      printf("%d\n", ages[i]);
      // > 20, 30, 40
  }
}

// print item that starts with b
int main() {
  char arr[3][10] = {"foo", "bar", "baz"};

  for (int i=0; i<3; i++) {
    // comparison against a string literal
    if (arr[i][0] == 'b') {
      printf("%s\n", arr[i]); 
      // > bar, baz
    }
  }
}

// get index of character
int main() {
  char username[] = "zachking";

  for (int i=0; i<sizeof(username); i++) {
    if (username[i] == 'z') {
      printf("%d\n", i);
      // > 0
    }
  }
}


/*
  User input
*/

// form
int main() {
  char name[10];
  int age;

  // Name
  printf("What is your name?\n");
  scanf("%s", name);

  // Age
  printf("How old are you?\n");
  scanf("%d", &age);

  // Result
  printf("---\n");
  printf("Name: %s\nAge: %d\n", name, age);
  printf("---\n");

  /*
    ---
    Name: Taemin
    Age: 34
    ---
  */
}


/*
  File
*/

// get person's information and create file about him/her.
struct Person {
  char name[50];
  int age;
};

int main() {
  struct Person person;
  FILE *fptr;

  printf("What is your name?\n");
  scanf("%s", person.name);

  printf("How old are you?\n");
  scanf("%d", &person.age);

  fptr = fopen("data.txt", "w");

  fprintf(fptr, "Person\nname: %s\nage: %d", person.name, person.age);

  fclose(fptr);
}
