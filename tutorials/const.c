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
  
  // car.price = 3000;

  printf("%d\n", car.price);
}