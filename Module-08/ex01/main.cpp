
#include "Span.hpp"
#include <iostream>

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  Span sp2 = Span(10000);
  std::vector<int> largeNumbers;
  for (int i = 0; i < 10000; ++i) {
    largeNumbers.push_back(i * 2);
  }
  sp2.addNumbers(largeNumbers.begin(), largeNumbers.end());
  std::cout << sp2.shortestSpan() << std::endl;
  std::cout << sp2.longestSpan() << std::endl;
  return 0;
}
