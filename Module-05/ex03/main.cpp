
#include "Intern.hpp"

int main() {
  Intern someRandomIntern;
  AForm *form;

  form = someRandomIntern.makeForm("robotomy request", "Bender");
  std::cout << form->getName() << std::endl;

  form = someRandomIntern.makeForm("presidential pardon", "Zaphod");
  std::cout << form->getName() << std::endl;

  form = someRandomIntern.makeForm("coffee form", "Nobody");

  return 0;
}
