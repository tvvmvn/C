#include <stdio.h>

int main(int argc, char const *argv[])
{
  char greeting[] = "hello";

  greeting[0] = 'H';

  printf("%s\n", greeting);
  
  return 0;
}
