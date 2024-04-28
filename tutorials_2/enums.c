/* 
  * enums (enumeration)

  a group of constants
*/

enum StatusCode {
  Success = 200,
  BadRequest = 400,
  NotFound = 404,
  InternalServerError = 500
};

int main() {
  enum StatusCode status = Success;

  printf("%d\n", status); 
  // > 200
}