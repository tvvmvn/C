#include <stdio.h>
#include <string.h>

struct Person {
  char data;
  int age;
};

int main() {

  struct Person person = {'A', 30};

  printf("%c\n", person.data);
  printf("%d\n", person.age);
}