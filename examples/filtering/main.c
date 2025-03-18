#include <stdio.h>

int main(int argc, char const *argv[])
{

  int nums[] = {10, 20, 30};
  int length = sizeof(nums) / sizeof(nums[0]);

  for (int i = 0; i < length; i++) {
    if (nums[i] > 10) {
      printf("%d\n", nums[i]);
    }
  }

  /* code */
  return 0;
}

