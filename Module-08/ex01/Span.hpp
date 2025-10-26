#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>

class Span {
private:
  unsigned int _maxSize;
  std::vector<int> _numbers;

public:
  Span();
  Span(unsigned int n);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int number);
  int shortestSpan() const;
  int longestSpan() const;
  void addNumbers(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end);
};

#endif
