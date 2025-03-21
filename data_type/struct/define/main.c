#include <stdio.h>
#include <string.h>

struct Person {
  char data;
  int age;
};

int main() {

  struct Person person;
  
  person.data = 'A';
  person.age = 20;

  printf("%c\n", person.data);
  printf("%d\n", person.age);
}