#include <stdio.h>
#include <string.h>

struct Person {
  char name[10];
  int age;
};

int main() {
  struct Person person;

  strcpy(person.name, "John");
  person.age = 20;

  printf("%s, %d years old", person.name, person.age);
}