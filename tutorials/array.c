/*
  Array
  Data type that have values more than one.
*/

// Memory wastage
int main() {
  char arr[3][10] = {"foo", "bar", "baz"};

  for (int i=0; i<3; i++)
    printf("%s\n", arr[i]);
};

// solution
int main() {
  char *arr[] = {"foo", "bar", "baz"};

  for (int i=0; i<3; i++)
    printf("%s\n", arr[i]);
}