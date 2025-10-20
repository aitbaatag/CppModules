
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
int main() {

  double x = std::nan("");
  std::cout << (x == x); // prints 0 (false)
  std::cout << x << std::endl;
  return 0;
}
