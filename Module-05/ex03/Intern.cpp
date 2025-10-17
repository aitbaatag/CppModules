
#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { *this = other; }
Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
    // No member variables to copy
  }
  return *this;
}
Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) {

  const std::string formNames[3] = {"shrubbery creation", "robotomy request",
                                    "presidential pardon"};

  FormCreator creators[3] = {&Intern::createShrubbery, &Intern::createRobotomy,
                             &Intern::createPresidential};

  for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      return (this->*creators[i])(target);
    }
  }

  std::cerr << "Form name '" << formName << "' doesn't exist!" << std::endl;
  return NULL;
}

AForm *Intern::createShrubbery(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) {
  return new PresidentialPardonForm(target);
}
