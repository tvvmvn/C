#include <stdio.h>

int main(int argc, char const *argv[])
{

  for (int i = 0; i < 3; i++) {
    if (i == 2) break;

    printf("%d times executed\n", i);
  }

  /* code */

  return 0;
}

