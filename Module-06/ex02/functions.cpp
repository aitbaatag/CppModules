#include "functions.hpp"

Base *generate(void) {
  int r = rand() % 3;
  switch (r) {
  case 0:
    std::cout << "Generated A\n";
    return new A();
  case 1:
    std::cout << "Generated B\n";
    return new B();
  default:
    std::cout << "Generated C\n";
    return new C();
  }
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A\n";
  else if (dynamic_cast<B *>(p))
    std::cout << "B\n";
  else if (dynamic_cast<C *>(p))
    std::cout << "C\n";
  else
    std::cout << "Unknown\n";
}

void identify(Base &p) {
  try {
    A &a = dynamic_cast<A &>(p);
    (void)a;
    std::cout << "A\n";
    return;
  } catch (const std::exception &e) {
  }
  try {
    B &b = dynamic_cast<B &>(p);
    (void)b;
    std::cout << "B\n";
    return;
  } catch (const std::exception &e) {
  }
  try {
    C &c = dynamic_cast<C &>(p);
    (void)c;
    std::cout << "C\n";
    return;
  } catch (const std::exception &e) {
  }
  std::cout << "Unknown\n";
}
