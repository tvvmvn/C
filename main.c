#include <stdio.h>
#include <stdlib.h>


typedef struct {
  char* name;
  int price;
} Car;

int main() {
  Car car = {"XM3", 3000};
  Car* p = &car;

  printf("%s\n", p->name);
}