#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

// init container   in cpp 98
int main() {
  std::vector<int> vec;
  for (int i = 0; i < 10; ++i) {
    vec.push_back(i);
  }
  std::list<int> lst;
  for (int i = 20; i < 30; ++i) {
    lst.push_back(i);
  }

  try {
    std::vector<int>::iterator it_vec = easyfind(vec, 3);
    std::cout << "Found in vector: " << *it_vec << std::endl;

    std::list<int>::iterator it_lst = easyfind(lst, 25);
    std::cout << "Found in list: " << *it_lst << std::endl;
  } catch (const std::runtime_error &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
