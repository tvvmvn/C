#include <stdio.h>
#include <stdlib.h>

// typedef int fuck -> define int as fuck (alias)
// typedef struct _Person -> define struct _Person as Person (alias)
typedef struct _Person {
  int age;
} Person;

int main(int argc, char const *argv[]) {

  Person person = {30};

  printf("%c\n", person.age);

  return 0;
}

