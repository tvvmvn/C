/*
  const (constant)

  unchangeable value
*/


int main() {
  const float PI = 3.14;

  printf("%f", PI);
}


struct Car {
  char name[10];
  int price;
};

int main() {
  const struct Car car = {"Avante", 2500};

  /*
    - lvalue 
    object that persists beyond a single expression. 
    
    - rvalue 
    temporary value that does not persist beyond the expression that uses it.
  */
  
  // car.price = 3000;
  // error message: expression must be a modifiable lvalue.

  printf("%d\n", car.price);
}