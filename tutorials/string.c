/*
  String
  a sequance of characters.

  1 declaration
  2 string function
*/


int main() {
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // sizeof also includes the \0 character

  printf("%d", strlen(alphabet));   
  // > 26
  printf("%d", sizeof(alphabet));   
  // > 27
}


// string function
int main() {
  char foo[] = "foo";
  char bar[] = "bar";

  // 0 if equal
  // not 0 if not equal
  printf("%d\n", strcmp(foo, bar));
  // > 4
}