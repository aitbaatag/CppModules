
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <vector>

class PmergeMe {
public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void parseInput(int argc, char *argv[]);
  std::vector<int> fordJohnsonSortVector(const std::vector<int> &input);
  std::deque<int> fordJohnsonSortDeque(const std::deque<int> &input);

  void printContainer(const std::vector<int> &container) const;
  void printContainer(const std::deque<int> &container) const;

  double getVectorSortTime() const;
  double getDequeSortTime() const;

private:
  double vectorSortTime;
  double dequeSortTime;

  std::vector<int> generateJacobsthalSequence(int n) const;

  std::vector<int> recursiveVectorSort(const std::vector<int> &input);
  std::deque<int> recursiveDequeSort(const std::deque<int> &input);

  void insertSorted(std::vector<int> &sorted, int value);
  void insertSorted(std::deque<int> &sorted, int value);

  std::vector<std::pair<int, int>>
  createAndSortPairsVector(const std::vector<int> &input);

  std::deque<std::pair<int, int>>
  createAndSortPairsDeque(const std::deque<int> &input);

  std::vector<int>
  ExtractLargerElementsVector(const std::vector<std::pair<int, int>> &pairs);
  std::deque<int>
  ExtractLargerElementsDeque(const std::deque<std::pair<int, int>> &pairs);
};

#endif // PMERGEME_HPP
