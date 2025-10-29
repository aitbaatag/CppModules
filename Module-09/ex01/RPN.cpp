
#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
  if (this != &other)
    stack = other.stack;
  return *this;
}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) const {
  std::stack<int> tempStack;
  std::istringstream ss(expression);
  std::string token;

  while (ss >> token) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      if (tempStack.size() < 2)
        throw std::runtime_error("Error: bad expression.");

      int b = tempStack.top();
      tempStack.pop();
      int a = tempStack.top();
      tempStack.pop();
      int result = 0;

      if (token == "+")
        result = a + b;
      else if (token == "-")
        result = a - b;
      else if (token == "*")
        result = a * b;
      else {
        if (b == 0)
          throw std::runtime_error("Error: division by zero.");
        result = a / b;
      }
      tempStack.push(result);
    } else {
      if (token.size() != 1 || token[0] < '0' || token[0] > '9')
        throw std::runtime_error("Error: bad input.");
      int value = token[0] - '0';
      tempStack.push(value);
    }
  }

  if (tempStack.size() != 1)
    throw std::runtime_error("Error: bad expression.");

  return tempStack.top();
}
