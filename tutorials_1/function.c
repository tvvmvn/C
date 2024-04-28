/*
  function

  a block of code when it is invoked

  1 declaration
*/


// function declaration and definition
void add(int x, int y) {
  printf("%d", x + y);
}

int main() {
  add(1, 2);
}


// or seperate to readabiliy:

// function declaration 
int add(int, int);

int main() {
  int r = add(1, 2);

  printf("%d\n", r);
}

// function definition 
int add(int x, int y) {
  return x + y;
}

/*
  array argument
*/

void f(int arr[3]) {
  for (int i = 0; i < 3; i++) {
    printf("%d\n", arr[i]);
  }
}

int main() {
  int arr[3] = {10, 20, 30};

  f(arr);
  // f({10, 20, 30}); // expected an expression
} 


/*
  References

  callback
  return multiple values
*/


void f(void callback(int)) {
  callback(2);
}

void cb(int n) {
  printf("%d\n", n);
}

int main() {
  f(cb);
}



void f(int* adr1, int* adr2) {
  *adr1 = 1;
  *adr2 = 2;
}

int main() {
  int x, y;

  f(&x, &y);

  printf("%d %d\n", x, y);
}