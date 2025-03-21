#include <stdio.h>
#include <string.h>

struct Person {
  char data;
  int age;
};

int main() {

  struct Person person1 = {'A', 30};
  struct Person person2;

  person2 = person1;
  
  printf("%c\n", person2.data);
  printf("%d\n", person2.age);
}