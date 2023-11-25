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
  References

  callback
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