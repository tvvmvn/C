#include <stdio.h>

struct Person {
  int age;
};

int main(int argc, char const *argv[]) {

  struct Person person;
  person.age = 30;

  // define a pointer for struct
  struct Person* p_person = &person;

  // access structure with pointer
  printf("%d\n", p_person->age);
  
  return 0;
}
