
#include "Array.hpp"
#include <iostream>

int main() {
  Array<int> numbers(5);
  for (unsigned int i = 0; i < numbers.getSize(); i++)
    numbers[i] = i * 2;

  for (unsigned int i = 0; i < numbers.getSize(); i++)
    std::cout << numbers[i] << " ";
  std::cout << std::endl;

  try {
    std::cout << numbers[10] << std::endl; // throws
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  Array<std::string> strings(3);
  strings[0] = "Hello";
  strings[1] = "World";
  strings[2] = "!";

  for (unsigned int i = 0; i < strings.getSize(); i++)
    std::cout << strings[i] << std::endl;
}
