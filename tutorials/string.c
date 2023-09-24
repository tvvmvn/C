/*
  String
  a sequance of characters.
*/

int main() {
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  // sizeof also includes the \0 character

  printf("%d", strlen(alphabet));   
  // > 26
  printf("%d", sizeof(alphabet));   
  // > 27
}