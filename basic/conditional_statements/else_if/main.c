#include <stdio.h>

int main() {
  int age = 20;

  if (age < 18) {
    printf("Kids");
  } else if (age >= 18 && age < 40) {
    printf("Young man");
  } else {
    printf("Old man");
  }
}