#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Struct type
struct Car {
  char name[10];
  int price;
  int available;
};

struct Car getCar() {
  struct Car car = {"AVANTE", 30, 1};
  
  return car;
}

int main() {
  struct Car car = getCar();
  
  printf("%s\n", car.name);
}

// Callback
void f(int cb()) {
  int x = cb();
  printf("%d\n", x);
}

int cb() {
  return 1;
}

int main() {
  f(cb);
}

/*
  Declare string variable with pointer

  char c = 'C'; char* p = &c;
*/

int main() {
  char* p = "foo"; // p stores address of 'f'

  printf("%c\n", *p); 
  // f
  printf("%c\n", *(p + 1)); 
  // o
  printf("%c\n", *(p + 2)); 
  // o
}

int main() {
  char p[] = "bar"; // p stores address of 'b'

  printf("%c\n", *p); // b
  printf("%c\n", *(p + 1)); // a
  printf("%c\n", *(p + 2)); // r
}

int main() {
  char p[] = {'b', 'a', 'r', '\0'}; // p stores address of 'b'

  printf("%c\n", *p);
  printf("%c\n", *(p + 1));
  printf("%c\n", *(p + 2));
}

int main() {
  int p[] = {10, 20, 30}; // p stores address of 10

  printf("%d\n", *p);
  printf("%d\n", *(p + 1));
  printf("%d\n", *(p + 2));
}


// char* p[3] = {"foo", "bar", "baz"};
// printf("%d\n", !NULL); // 1
// printf("%d\n", !34); // 0
// printf("%d\n", !0); // 1
// printf("%d\n", !"foo"); // 0
// printf("%d\n", !""); // ** 0
// printf("%d\n", !'A'); // 0
// printf("%d\n", NULL == 0); // 1
// printf("%d\n", n); // 1
// printf("%c\n", c); // x00
// printf("%p\n", NULL); // 0x0

// int main() {
//   int arr[9];

//   arr[3] = 1;
//   arr[4] = 2;

//   for (int i=0; i<9; i++) {
//     if (arr[i] == 1)  {
//       printf("USER %d\n", i);
//     }
//     if (arr[i] == 2) {
//       printf("COM %d\n", i);
//     }
//   }
// }

enum Grid {
  OFFSET_X = 50,
  OFFSET_Y = 50,
  CELL = 20
};

enum Direction {
  TOP, LEFT, RIGHT, BOTTOM
};

struct Snake {
  int x;
  int y;
  int _x;
  int _y;
  int size;
  int moving_point;
  int node[3][2];
  int dir;
};

int main() {
  struct Snake snake = 
  {
    OFFSET_X, 
    OFFSET_Y, 
    0, 
    0, 
    CELL, 
    20, 
    {{40, 0}, {20, 0}, {0, 0}}, // or struct(crds) array
    RIGHT
  };

  for (int i=0; i<3; i++) {
    for (int j=0; j<2; j++) {
      printf("%d ", snake.node[i][j]);
    }
    printf("\n");
  }
}

enum Grid {
  SIZE = 300,
  ITEM_COUNT = 3,
  ITEM_SIZE = SIZE / ITEM_COUNT
};

struct Car {
  char name[10];
  int price;
};

int main() {
  const struct Car avante = {"Avante", 2500};
  // avante.price = 3000;

  printf("%d\n", avante.price);
}

int main() {
  printf("%d\n", 0 == NULL); // 1
  printf("%d\n", "" == 0); // 0
  printf("%d\n", 0 == false); // 1
  printf("%d\n", "2023" == 2023); // 0
  printf("%d\n", !0); // 1
}