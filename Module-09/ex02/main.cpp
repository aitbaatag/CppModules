
#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main(int argc, char **argv) {
  try {
    if (argc < 2) {
      std::cerr << "Error: no input numbers provided." << std::endl;
      return 1;
    }

    PmergeMe sorter;
    sorter.parseInput(argc, argv);

    // init containers
    std::vector<int> vecInput;
    std::deque<int> deqInput;
    for (int i = 1; i < argc; ++i) {
      std::istringstream ss(argv[i]);
      int num;
      ss >> num;
      vecInput.push_back(num);
      deqInput.push_back(num);
    }

    std::cout << "Before: ";
    sorter.printContainer(vecInput);
    std::cout << std::endl;

    // ---- Vector timing ----
    std::vector<int> sortedVec = sorter.fordJohnsonSortVector(vecInput);

    // ---- Deque timing ----
    std::deque<int> sortedDeq = sorter.fordJohnsonSortDeque(deqInput);

    std::cout << "After: vector: ";
    sorter.printContainer(sortedVec);
    std::cout << std::endl;
    std::cout << "After: deque : ";
    sorter.printContainer(sortedDeq);
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << vecInput.size()
              << " elements with std::vector : " << sorter.getVectorSortTime()
              << " us" << std::endl;
    std::cout << "Time to process a range of " << deqInput.size()
              << " elements with std::deque  : " << sorter.getDequeSortTime()
              << " us" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
