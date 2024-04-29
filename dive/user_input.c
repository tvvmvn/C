#include <stdio.h>
#include <string.h>


/*
User input

1 scanf(format specifier, reference operator)
2 getchar

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

int main() {
  int a;
  int b;

  printf("enter two numbers to add\n");

  while (scanf("%d %d", &a, &b) < 2) {
    printf("try again\n");
    scanf("%*s");
  }

  printf("result: %d\n", a + b);
}

// get single character
int main()
{
    int character;
    character = getchar();
 
    printf("The entered character is : %c", character);
    return 0;
}

// keep getting a single character
int main() {
  char c;

  printf("Type a single character\n");

  while (1) {
    c = getchar();

    if (c != '\n') {
      printf("The character: ");
      putchar(c);
      printf("\nOK. one more\n");
    }
  }
}