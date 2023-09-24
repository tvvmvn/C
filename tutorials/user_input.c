/*
  User input

  scanf(format specifier, reference operator)

  * reference operator
  stores the memory address of the variable.
*/

int main() {
  char name[10];

  printf("What is your name?");

  scanf("%s", name);

  printf("Hi, %s!", name);
}