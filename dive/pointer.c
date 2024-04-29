/*
  when should we use pointer?

  for saving memory and modularity

  1 saving memory
  It allows dynamic allocation

  2 modularity
  function
*/


/*
Memory address
*/


int main() {
  int year = 2024;
  int* p = &year;

  printf("%p\n", p); // 0x7ff7bfeff32c
}


/*
string array with pointer
*/


int main() {
  char* arr[3] = {"foo", "bar", "baz"};

  for (int i = 0; i < 3; i++)
    printf("%s ", arr[i]); // foo bar baz
}


/*
array with pointer  
*/


int main() {
  int* gen;

  *gen = 10; // gen[0] = 10
  *(gen + 1) = 20; // gen[1] = 20
  *(gen + 2) = 30; // gen[2] = 30

  for (int i = 0; i < 3; i++) 
    printf("%d ", gen[i]); // 10 20 30
}


/*
A function which returns array
*/


int* getArr() {
  int* p;

  *p = 10;
  *(p + 1) = 20;
  *(p + 2) = 30;

  return p;
}

int main() {
  int* arr = getArr();

  printf("%d ", *arr); // 10
  printf("%d ", *(arr + 1)); // 20
  printf("%d ", *(arr + 2)); // 30
}


/*
array and pointer
*/


int main() {
  int gen[] = {10, 20, 30};

  for (int i = 0; i < 3; i++)
    printf("%p\n", gen + i);
}




/*
NULL pointer
*/


int main() {

  int* p = NULL;

  printf("%d\n", p == NULL); // 1
}



/*
string with pointer
*/


int main() {
  char* s = "hello C!";

  printf("%s\n", s); // hello C!
}


/*
A function which returns string
*/


char* getS() {
  return "hello C!";
}

int main() {
  char* s = getS();

  printf("%s\n", s);
}




/*
struct with pointer
*/


struct Car {
  int price;
  int year;
};

int main() {
  struct Car* p;

  p->price = 3000;
  p->year = 2020;

  printf("price: %d\n", p->price);
  printf("year: %d\n", p->year);
}


/*
pointer to struct
*/


typedef struct {
  char* name;
  int price;
} Car;

int main() {
  Car car = {"XM3", 3000};
  Car* p = &car;

  printf("%s\n", p->name);
}


/*
A function returning pointer to struct 
*/


struct Car {
  char* name;
  int price;
};

struct Car* getCar() {
  struct Car* car;

  car->name = "XM3";
  car->price = 3000;

  return car;
}

int main() {
  struct Car* car = getCar();

  printf("%s\n", car->name); // XM3
}