/*
DATA TYPES
*/


/*
1 int
integer
*/


int main() {
  int year = 2023;
  
  printf("%d\n", year);
}


/*
2 float and double

stores fractional numbers(분수)

1) float
sufficient for storing 6-7 decimal digits(십진수)

2) double √
sufficient for storing 15 decimal digits(십진수)
*/


int main() {
  float half = 0.5;

  printf("%f\n", half);
}


/*
3 char
a single chracter
*/


int main() {
  char a = 'A';
  
  printf("%c\n", a);
}


/*
typedef
*/


int main() {
  typedef int INT;

  INT year = 2024;

  printf("%d\n", year);
}


/*
  Type Casting
*/


int main() {
  int num1 = 5;
  int num2 = 2;
  float sum = (float) num1 / num2;

  printf("%f", sum); // 2.500000
}


/*
* References

1 integer

short int: 
-32,768 to 32,768

unsigned short int: 
0 to 65,535

int: 
-2,147,483,648 to 2,147,483,647

unsigned int: 
0 to 4,294,967,295

long int:
-2,147,483,648 to 2,147,483,647

unsigned long int:
0 to 4,294,967,295

long long int:
-(2^63) to (2^63)-1

unsigned long long int:
0 to 18,446,744,073,709,551,615


2 character 

signed char:
-128 to 127
unsigned char:
0 to 255


3 fractional number

float:
1.2e-38 to 3.4e+38

double:
1.7e-308 to 1.7e+308

long double:
3.4e-4932 to 1.1e+4932
*/