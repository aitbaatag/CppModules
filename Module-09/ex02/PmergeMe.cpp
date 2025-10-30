#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vectorSortTime(0.0), dequeSortTime(0.0) {}
PmergeMe::PmergeMe(const PmergeMe &other)
    : vectorSortTime(other.vectorSortTime), dequeSortTime(other.dequeSortTime) {
}
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    vectorSortTime = other.vectorSortTime;
    dequeSortTime = other.dequeSortTime;
  }
  return *this;
}
PmergeMe::~PmergeMe() {}

// ---------------- Input Parsing ----------------
void PmergeMe::parseInput(int argc, char *argv[]) {
  std::set<int> unique;

  for (int i = 1; i < argc; ++i) {
    std::string arg = argv[i];
    for (size_t j = 0; j < arg.size(); ++j)
      if (!isdigit(arg[j]))
        throw std::runtime_error("Error: invalid input '" + arg + "'");

    int num;
    std::istringstream ss(arg);
    ss >> num;
    if (num < 0)
      throw std::runtime_error("Error: negative number not allowed");
    if (!unique.insert(num).second)
      throw std::runtime_error("Error: duplicate number '" + arg + "'");
  }
}

// ---------------- Vector Version ----------------
std::vector<int>
PmergeMe::fordJohnsonSortVector(const std::vector<int> &input) {
  clock_t start = clock();
  std::vector<int> result = recursiveVectorSort(input);
  clock_t end = clock();
  vectorSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
  return result;
}

std::vector<int> PmergeMe::recursiveVectorSort(const std::vector<int> &input) {
  if (input.size() <= 1)
    return input;

  bool hasOdd = (input.size() % 2 == 1);
  int leftover = 0;
  if (hasOdd)
    leftover = input.back();

  std::vector<std::pair<int, int> > pairs = createAndSortPairsVector(input);
  std::vector<int> mainChain = ExtractLargerElementsVector(pairs);

  if (mainChain.size() > 1)
    mainChain = recursiveVectorSort(mainChain);

  for (size_t i = 0; i < pairs.size(); ++i) {
    std::vector<int>::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].first);
    mainChain.insert(pos, pairs[i].first);
  }

  if (hasOdd) {
    std::vector<int>::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
    mainChain.insert(pos, leftover);
  }

  return mainChain;
}

std::vector<std::pair<int, int> >
PmergeMe::createAndSortPairsVector(const std::vector<int> &input) {
  std::vector<std::pair<int, int> > pairs;
  for (size_t i = 0; i + 1 < input.size(); i += 2)
    pairs.push_back(std::make_pair(std::min(input[i], input[i + 1]),
                                   std::max(input[i], input[i + 1])));
  return pairs;
}

std::vector<int> PmergeMe::ExtractLargerElementsVector(
    const std::vector<std::pair<int, int> > &pairs) {
  std::vector<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i)
    mainChain.push_back(pairs[i].second);
  return mainChain;
}

// ---------------- Deque Version ----------------
std::deque<int> PmergeMe::fordJohnsonSortDeque(const std::deque<int> &input) {
  clock_t start = clock();
  std::deque<int> result = recursiveDequeSort(input);
  clock_t end = clock();
  dequeSortTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
  return result;
}

std::deque<int> PmergeMe::recursiveDequeSort(const std::deque<int> &input) {
  if (input.size() <= 1)
    return input;

  bool hasOdd = (input.size() % 2 == 1);
  int leftover = 0;
  if (hasOdd)
    leftover = input.back();

  std::deque<std::pair<int, int> > pairs = createAndSortPairsDeque(input);
  std::deque<int> mainChain = ExtractLargerElementsDeque(pairs);

  if (mainChain.size() > 1)
    mainChain = recursiveDequeSort(mainChain);

  for (size_t i = 0; i < pairs.size(); ++i) {
    std::deque<int>::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].first);
    mainChain.insert(pos, pairs[i].first);
  }

  if (hasOdd) {
    std::deque<int>::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
    mainChain.insert(pos, leftover);
  }

  return mainChain;
}

std::deque<std::pair<int, int> >
PmergeMe::createAndSortPairsDeque(const std::deque<int> &input) {
  std::deque<std::pair<int, int> > pairs;
  for (size_t i = 0; i + 1 < input.size(); i += 2)
    pairs.push_back(std::make_pair(std::min(input[i], input[i + 1]),
                                   std::max(input[i], input[i + 1])));
  return pairs;
}

std::deque<int> PmergeMe::ExtractLargerElementsDeque(
    const std::deque<std::pair<int, int> > &pairs) {
  std::deque<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i)
    mainChain.push_back(pairs[i].second);
  return mainChain;
}

void PmergeMe::printContainer(const std::vector<int> &container) const {
  for (size_t i = 0; i < container.size(); ++i)
    std::cout << container[i] << " ";
  std::cout << std::endl;
}

void PmergeMe::printContainer(const std::deque<int> &container) const {
  for (size_t i = 0; i < container.size(); ++i)
    std::cout << container[i] << " ";
  std::cout << std::endl;
}

double PmergeMe::getVectorSortTime() const { return vectorSortTime; }
double PmergeMe::getDequeSortTime() const { return dequeSortTime; }
