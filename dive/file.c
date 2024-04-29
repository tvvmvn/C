#include <stdio.h>


// Create a file.
int main() {
  FILE *fptr;

  fptr = fopen("data.txt", "w");

  fclose(fptr);
}

// Write a file
int main() {
  FILE *fptr;

  fptr = fopen("data.txt", "w");

  fprintf(fptr, "...");

  fclose(fptr);
}

// Append a file
int main() {
  FILE *fptr;

  fptr = fopen("data.txt", "a");

  fprintf(fptr, "\n...");

  fclose(fptr);
}

// Read a file
int main() {
  FILE *fptr;

  fptr = fopen("data.txt", "r");

  if (fptr != NULL) {
    char content[100];

    while(fgets(content, 100, fptr)) {
      printf("%s", content);
    }
  } else {
    // If you try to open a file for reading that does not exist, 
    // the fopen() function will return NULL.
    printf("Not able to open the file.");
  }

  fclose(fptr);
}
