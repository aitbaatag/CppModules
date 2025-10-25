
#include "iter.hpp"
#include <iostream>

void printInt(int &n) { std::cout << n << " "; }

void printConstInt(const int &n) { std::cout << n << " "; }

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  size_t length = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Array elements: ";
  iter(arr, length, &printInt);
  std::cout << std::endl;

  // Test with const array
  const int constArr[] = {10, 20, 30, 40};
  std::cout << "Const array elements: ";
  iter<int>(constArr, 4, &printConstInt);
  std::cout << std::endl;

  return 0;
}
