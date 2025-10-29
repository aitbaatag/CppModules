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

  // Separate odd element if exists
  bool hasOdd = (input.size() % 2 == 1);
  int straggler = hasOdd ? input.back() : 0;
  size_t pairCount = input.size() / 2;

  // TODO : call function to create pairs and sort them function name is
  // createAndSortPairs
  std::vector<std::pair<int, int>> pairs;
  for (size_t i = 0; i < pairCount; ++i) {
    int a = input[i * 2];
    int b = input[i * 2 + 1];
    pairs.push_back(a < b ? std::make_pair(a, b) : std::make_pair(b, a));
  }

  // TODO: call function to extract larger elements for main chain function name
  // is extractLargerElements
  std::vector<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i)
    mainChain.push_back(pairs[i].second);

  mainChain = recursiveVectorSort(mainChain);

  // Insert first smaller element at beginning
  if (!pairs.empty())
    mainChain.insert(mainChain.begin(), pairs[0].first);

  std::vector<int> jacob = generateJacobsthalSequence(pairs.size());
  std::vector<int> insertOrder;
  std::vector<bool> used(pairs.size(), false);

  for (size_t j = 0; j < jacob.size(); ++j) {
    size_t idx = jacob[j] - 1;
    if (idx > 0 && idx < pairs.size()) {
      insertOrder.push_back(idx);
      used[idx] = true;
    }
  }

  for (size_t i = 1; i < pairs.size(); ++i)
    if (!used[i])
      insertOrder.push_back(i);

  for (size_t i = 0; i < insertOrder.size(); ++i)
    insertSorted(mainChain, pairs[insertOrder[i]].first);

  if (hasOdd)
    insertSorted(mainChain, straggler);

  return mainChain;
}

void PmergeMe::insertSorted(std::vector<int> &sorted, int value) {
  std::vector<int>::iterator pos =
      std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(pos, value);
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

  // Separate odd element if exists
  bool hasOdd = (input.size() % 2 == 1);
  int straggler = hasOdd ? input.back() : 0;
  size_t pairCount = input.size() / 2;

  // Create and sort pairs
  std::deque<std::pair<int, int>> pairs;
  for (size_t i = 0; i < pairCount; ++i) {
    int a = input[i * 2];
    int b = input[i * 2 + 1];
    pairs.push_back(a < b ? std::make_pair(a, b) : std::make_pair(b, a));
  }

  // Extract larger elements for main chain
  std::deque<int> mainChain;
  for (size_t i = 0; i < pairs.size(); ++i)
    mainChain.push_back(pairs[i].second);

  // Recursively sort the main chain
  mainChain = recursiveDequeSort(mainChain);

  // Insert first smaller element at beginning
  if (!pairs.empty())
    mainChain.push_front(pairs[0].first);

  std::vector<int> jacob = generateJacobsthalSequence(pairs.size());
  std::vector<int> insertOrder;
  std::vector<bool> used(pairs.size(), false);

  for (size_t j = 0; j < jacob.size(); ++j) {
    size_t idx = jacob[j] - 1;
    if (idx > 0 && idx < pairs.size()) {
      insertOrder.push_back(idx);
      used[idx] = true;
    }
  }

  for (size_t i = 1; i < pairs.size(); ++i)
    if (!used[i])
      insertOrder.push_back(i);

  for (size_t i = 0; i < insertOrder.size(); ++i)
    insertSorted(mainChain, pairs[insertOrder[i]].first);

  // Insert straggler if exists
  if (hasOdd)
    insertSorted(mainChain, straggler);

  return mainChain;
}

void PmergeMe::insertSorted(std::deque<int> &sorted, int value) {
  std::deque<int>::iterator pos =
      std::lower_bound(sorted.begin(), sorted.end(), value);
  sorted.insert(pos, value);
}

// ---------------- Jacobsthal Sequence ----------------
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) const {
  std::vector<int> seq;
  if (n <= 0)
    return seq;

  int j0 = 0, j1 = 1;
  while (j1 <= n) {
    seq.push_back(j1);
    int next = j1 + 2 * j0;
    j0 = j1;
    j1 = next;
  }
  return seq;
}

// ---------------- Print Containers ----------------
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

// ---------------- Get Times ----------------
double PmergeMe::getVectorSortTime() const { return vectorSortTime; }
double PmergeMe::getDequeSortTime() const { return dequeSortTime; }
