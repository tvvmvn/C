/* 
struct (structure)

Template for object.
*/

struct HybridCar {
  char model[30];
  char brand[10];
  int price;
};

int main() {
  struct HybridCar avante = {"Avante", "Hyundai", 2500};
  struct HybridCar xm3 = {"XM3", "Renault", 3000};

  printf("%s %s - %d\n", avante.brand, avante.model, avante.price);
  printf("%s %s - %d\n", xm3.brand, xm3.model, xm3.price);
}