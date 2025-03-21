#include <stdio.h>


int main(int argc, char const *argv[]) {

  int n = 2;
  char c = 'A';

  // pointer with type void* can store all types of pointers.
  void* p1 = &n;
  void* p2 = &c;

  // access with explicit type conversion
  printf("%d\n", *(int*)p1);
  printf("%c\n", *(char*)p2);
}