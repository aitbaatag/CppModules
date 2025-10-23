#include "iter.hpp"
#include <iostream>

void printInt(int &n) { std::cout << n << " "; }
void incrementInt(int &n) { n++; }

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  size_t length = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Array elements: ";
  iter(arr, length, printInt);
  std::cout << std::endl;

  iter(arr, length, incrementInt);
  std::cout << "Incremented array elements: ";
  iter(arr, length, printInt);
  std::cout << std::endl;

  return 0;
}
