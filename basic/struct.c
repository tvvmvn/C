/* 
struct (structure)
data type than can holds multiple type of values.
*/


// definition
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


// update 
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
struct array
*/


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

  for (int i = 0; i < 3; i++) {
    printf("%d. %s from %s - %d\n", ++i, table[i].model, table[i].brand, table[i].price);
  }

  // 1. Avante from Hyundai - 2500
  // 2. XM3 from Renault - 3000
  // 3. KONA from Hyundai - 3000
}


/*
struct with array value
*/


typedef struct {
  char* brand;
  int size[3];
} Suitcase;

int main() {
  Suitcase suitcase = {"Samsonite", {20, 24, 28}};

  for (int i = 0; i < 3; i++) 
    printf("%d ", suitcase.size[i]); // 20 24 28
}


/*
nested struct
*/


typedef struct {
  int resolution;
  int refresh_rate;
} Display;

typedef struct {
  int ram;
  Display display;
} Computer;

int main() {
  Display display = {1080, 120};
  Computer com = {16, display};
  
  printf("%d\n", com.display.resolution); // 1080
}


/*
complex structure
*/


typedef struct {
  char* instrument;
  int career;
} Member;

typedef struct {
  char* genre;
  Member members[3];
} Band;

int main() {
  Band band = {"Rock", {
    {"Guitar", 10}, 
    {"Keyboard", 8}, 
    {"Drum", 12}, 
  }};

  printf("Band with ");
  for (int i = 0; i < 3; i++)
    printf("%s ", band.members[i].instrument);
    // Band with Guitar Keyboard Drum 
}



/*
A function which returns structure
*/


struct Car {
  char* name;
  int price;
};

struct Car getCar() {
  struct Car car = {"XM3", 3000};

  return car;
}

int main() {
  struct Car car = getCar();

  printf("%s\n", car.name);
}


/*
struct copy
*/


struct Piece {
  int id;
  int mcount;
};

int main() {
  struct Piece p1 = {1, 100};
  // copy p1
  struct Piece p2 = p1; 

  p2.mcount++;

  printf("%d\n", p1.mcount); // 100
}


/*
typedef with struct
*/


typedef struct {
  char* name;
} Car;

int main() {
  Car car = {"XM3"};

  printf("%s\n", car.name); // XM3
}



