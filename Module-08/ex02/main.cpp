#include "MutantStack.hpp"

int main() {
  MutantStack<int> mstack;
  mstack.push(1);
  mstack.push(2);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(4);
  mstack.push(5);
  //[...]
  mstack.push(6);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  std::cout << "\n";
  std::cout << "\033[33m" << "Test with begin and end\n" << "\033[0m";

  std::cout << "stack: " << std::endl;
  while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  std::cout << "\n";
  std::cout << "\033[33m" << "Test with rbegin and rend\n" << "\033[0m";

  MutantStack<int>::reverse_iterator rit = mstack.rbegin();
  MutantStack<int>::reverse_iterator rite = mstack.rend();

  std::cout << "stack: " << std::endl;
  while (rit != rite) {
    std::cout << *rit << " " << std::endl;
    ++rit;
  }
  return 0;
}
