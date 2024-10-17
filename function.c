#include <stdio.h>


void isAdult(int age) {
  if (age >= 18) {
    printf("Adult");
  } else {
    printf("Not an adult");
  };
};

int main() {
  isAdult(20);
}