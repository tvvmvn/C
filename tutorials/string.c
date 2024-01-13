/*
  String
  a sequance of characters.

  1 declaration
  2 acess each character
  3 change string
  4 get count of string
  5 string function
  6 escape character
*/

/*
  declaration
*/

int main() {
  char foo[] = "bar";

  printf("%s\n", foo);
}

int main() {
  char foo[] = {'b', 'a', 'r', '\0'};

  printf("%s\n", foo);
}


/*
  access each character
*/


int main() {
  char foo[] = "bar";

  printf("%c\n", foo[0]);
  // b
  printf("%c\n", foo[1]);
  // a
  printf("%c\n", foo[2]);
  // r
}


/*
  change string
*/


int main() {
  char foo[] = "bar";

  foo[2] = 'z';

  printf("%s\n", foo);
  // baz
}


/*
  get count of string
*/


int main() {
  char foo[] = "bar";

  printf("%d", strlen(foo));   
  // > 3
}


/*
  string function

  1 strcat
  2 strcmp
  3 strcpy
*/


// strcat: concatenate strings
int main() {
  char s1[20] = "Hello ";
  char s2[] = "World";

  strcat(s1, s2);

  printf("%s\n", s1); 
}


// strcmp: compare strings
int main() {
  char foo[] = "foo";
  char bar[] = "bar";

  // 0 if equal, not 0 if not equal
  printf("%d\n", strcmp(foo, bar));
  // > 4
}

// stcpy: copy string

int main() {
  char foo[10];

  // foo = "bar" (error, you cannot assign value to array)
  strcpy(foo, "bar");

  printf("%s\n", foo); // bar
}

/*
  escape character

  \" double quote
  \' single quote
  \\ backslash
  \n new line
  \t tab
  \0 null
*/