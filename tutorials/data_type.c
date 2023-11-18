/*
  DATA TYPES

  1 int
  integer

  2 float and double
  stores fractional numbers(분수)

  1) float
  sufficient for storging 6-7 decimal digits(십진수)

  2) double √
  sufficient for storging 15 decimal digits(십진수)

  3 char
  a single chracter
*/


int main() {
  int year = 2023;
  float half = 0.5;
  char a = 'A';

  printf("%d\n", year);
  printf("%f\n", half);
  printf("%c\n", a);
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