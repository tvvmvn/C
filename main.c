#include <stdio.h>
#include <stdlib.h>

struct Person {
  float height;
  float weight;
};

int main() {
  struct Person* person;
  person->height = 178.5;
  person->weight = 63;

  printf("height: %f\n", person->height);
  printf("weight: %f", person->weight);

  return 0;
};