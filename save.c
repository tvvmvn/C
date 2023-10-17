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

int main() {
  char pick;
  char board[] = {
    '1', '2', '3', 
    '4', '5', '6', 
    '7', '8', '9', 
    '\0'
  };

  while (1) {
    printf("choose 1 to 9\n");

    if (pick != '\n') {
      printf("=====\n");
      printf("%c %c %c\n", board[0], board[1], board[2]);
      printf("%c %c %c\n", board[3], board[4], board[5]);
      printf("%c %c %c\n", board[6], board[7], board[8]);
      printf("=====\n");
    }

    pick = getchar();

    if (pick != '\n') {
      for (int i=0; i<strlen(board); i++) {
        if (board[i] == pick) {
          board[i] = 'X';
          break;
        }
      }
    }
  }
}

int main() {
  char str[] = "123456789";
  int c;  

  printf("choose a number from 1 to 9\n");

  while (1) {
    c = getchar(); // a\n -> a + \n

    if (c != '\n') {
      int ok = 0;

      for (int i=0; i<strlen(str); i++) {
        if (str[i] == c) {
          ok = 1;
        }
      }

      if (ok) {
        printf("number: ");
        putchar(c);
        break;
      } else {
        printf("try again\n");
      }
    }
  }

  printf("\n---END---\n");
}

int main() {
  int a = 1;
  int b = '2'; // '2' -> 50
  int c = 3;
  int d = 4;

  // boring 
  // printf("%d\n", a);
  // printf("%d\n", b);
  // printf("%d\n", c);
  // printf("%d\n", c);

  int r = a + b + c + d;

  printf("%d\n", r);
}


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Tic Tac Toe
int main() {
  int input;
  char arr[9] = {
    '#', '#', '#',
    '#', '#', '#',
    '#', '#', '#',
  };

  // Initialization, should only be called once.
  srand(time(NULL));   
  // Returns a pseudo-random integer between 0 and RAND_MAX.


  while (1) {
    // print board
    printf("%c %c %c\n", arr[0], arr[1], arr[2]);
    printf("%c %c %c\n", arr[3], arr[4], arr[5]);
    printf("%c %c %c\n", arr[6], arr[7], arr[8]);
    
    while (scanf("%d", &input) != 1) { // 1 or 0
      // Tell the user that the entry was invalid
      printf("enter a valid number\n");
      /*
        Asterisk * tells scanf to read and ignore the value

        For scanf, the * indicates that the field is to be read but ignored, 
        so that e.g. scanf("%*d %d", &i) for the input "12 34" will ignore 12 
        and read 34 into the integer i.
      */
      scanf("%*s");
    }

    arr[--input] = 'O';

    // counterpart
    int r;

    while (1) {
      r = rand() % 9;  

      if (arr[r] == '#') {
        break;
      }
    }
    
    arr[r] = 'X';
  }
}


