#include <stdio.h>

int main(int argc, char const *argv[])
{

  int matrix[2][3] = {
    {10, 20, 30},
    {40, 50, 60},
  };

  printf("%d\n", matrix[0][1]);

  return 0;
}
