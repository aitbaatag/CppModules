#include "functions.hpp"

int main() {
  srand(std::time(0));
  Base *base = generate();

  identify(base);
  identify(*base);

  delete base;
  return 0;
}
