#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char* argv[]) {
  if (argc > 1) {
    // version check
    if (strcmp(argv[1], "-v") == 0) {
      printf("v1.0.0\n");
    }

    // tmj init
    if (strcmp(argv[1], "init") == 0) {
      // create an file..
    }
  } else {
    printf("Usage \n -v \t check the version \n ... \n");
  }
}