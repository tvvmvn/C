/* 
  struct (structure)

  data type than can holds multiple type of values.
*/


// declare struct
struct HybridCar {
  char model[30];
  char brand[10];
  int price;
};

// define an structure and access each value
int main() {
  struct HybridCar avante = {"Avante", "Hyundai", 2500};
  struct HybridCar xm3 = {"XM3", "Renault", 3000};

  printf("%s %s - %d\n", avante.brand, avante.model, avante.price);
  printf("%s %s - %d\n", xm3.brand, xm3.model, xm3.price);
}


// update value
struct Car {
  char name[10];
  int price;
};

int main() {
  struct Car car = {"Avante", 2500};
  
  car.price = 3000;

  printf("%d\n", car.price);
}


/* 
  Struct array
*/


// print car list
struct HybridCar {
  char model[30];
  char brand[10];
  int price;
};

int main() {
  struct HybridCar table[3] = {
    {"Avante", "Hyundai", 2500}, 
    {"XM3", "Renault", 3000},
    {"KONA", "Hyundai", 3000}
  };

  printf("Hybrid Car list\n");
  for (int i=0; i<3; i++) {
    printf("%d. %s from %s - %d\n", i+1, table[i].model, table[i].brand, table[i].price);
  }

  /*
    Hybrid Car list
    1. Avante from Hyundai - 2500
    2. XM3 from Renault - 3000
    3. KONA from Hyundai - 3000
  */
}