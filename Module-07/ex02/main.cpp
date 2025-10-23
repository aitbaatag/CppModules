#include "Array.hpp"
#include <iostream>

int main() {
  try {
    Array<int> intArray(5);
    for (size_t i = 0; i < intArray.getSize(); i++) {
      intArray[i] = i * 10;
    }

    std::cout << "Integer Array: ";
    for (size_t i = 0; i < intArray.getSize(); i++) {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "!";

    std::cout << "String Array: ";
    for (size_t i = 0; i < strArray.getSize(); i++) {
      std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    // throw an exception
    // std::cout << intArray[10] << std::endl;

  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
