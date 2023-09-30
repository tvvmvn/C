#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int clean_stdin() {
  int c;

  while (
    (c = getchar()) != '\n' && c != EOF
  );

  return 1;
}

int main() { 
  int rows = 0;  
  char c;
  
  do {  
    printf("Enter an integer from 1 to 9:\n");

  } while (
    (
      (
        scanf("%d%c", &rows, &c) != 2 || c!='\n'
      ) && 
      clean_stdin()
    ) || 
    rows<1 || rows>9
  );
}

int main() {
  int s = 13;
  int x;

  while (s--) {
      x = getchar();

      putchar(x);
  }
}

int main() {
  int ch, i = 0;
  char str[150];

  printf("Enter the characters\n");

  do {
    // takes character, number, etc from the user
    ch = getchar();

    // store the ch into str[i]
    str[i] = ch;

    // increment loop by 1
    i++;

    // ch is not equal to '\n'
  } while (ch != '\n');

  printf("Entered characters are %s ", str);
}

void empty_stdin(void) {
  int c = getchar();

  while (c != '\n' && c != EOF) 
    c = getchar();
}

int getint(int *value, const char *prompt) {

  /* loop continually until good input or canceled */
  for (;;) {
    int rtn;
    
    /* display prompt */
    fputs(prompt, stdout); 
    rtn = scanf("%d", value);

    /* user generated manual EOF */
    if (rtn == EOF) { 
      fputs("<user canceled input>\n", stderr);
      return 0;
    }

    /* all other cases - empty input buffer */
    empty_stdin(); 

    /* good input, break */
    if (rtn == 1)  
      break;

    /* otherwise matching failure */
    fputs("  error: invalid integer input.\n", stderr);
  }

  /* value also availale through pointer */
  return *value; 
}

int main(void) {
  int v, i = getint(&v, "enter integer value: ");

  if (i)
    printf("\ninteger: %d\n", v);

  return 0;
}

int main() {

  char str[] = {
    '1', '2', '3', 
    '4', '5', '6', 
    '7', '8', '9', 
    '\0'
  };
  char c;

  while (1) {

    // user turn
    while (1) {
      int r;

      c = getchar();

      for (int i=0; i<strlen(str); i++) {
        if (str[i] == c) {
          r = 1;
        }
      }

      if (r == 1) {
        break;
      }
    }

    // ..
  }
}