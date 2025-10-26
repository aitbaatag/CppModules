#include "Span.hpp"

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other)
    : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    _maxSize = other._maxSize;
    _numbers = other._numbers;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
  if (_numbers.size() >= _maxSize) {
    throw std::out_of_range("Span is full");
  }
  _numbers.push_back(number);
}

int Span::shortestSpan() const {
  if (_numbers.size() < 2) {
    throw std::logic_error("Not enough numbers to find a span");
  }
  std::vector<int> sortedNumbers = _numbers;
  std::sort(sortedNumbers.begin(), sortedNumbers.end());
  int minSpan = sortedNumbers[1] - sortedNumbers[0];
  for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
    int span = sortedNumbers[i + 1] - sortedNumbers[i];
    if (span < minSpan) {
      minSpan = span;
    }
  }
  return minSpan;
}

int Span::longestSpan() const {
  if (_numbers.size() < 2) {
    throw std::logic_error("Not enough numbers to find a span");
  }
  int minNumber = *std::min_element(_numbers.begin(), _numbers.end());
  int maxNumber = *std::max_element(_numbers.begin(), _numbers.end());
  return maxNumber - minNumber;
}

void Span::addNumbers(std::vector<int>::iterator begin,
                      std::vector<int>::iterator end) {
  size_t rangeSize = std::distance(begin, end);
  if (_numbers.size() + rangeSize > _maxSize) {
    throw std::out_of_range("Adding these numbers would exceed Span capacity");
  }
  _numbers.insert(_numbers.end(), begin, end);
}
