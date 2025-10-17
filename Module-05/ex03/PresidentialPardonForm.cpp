#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// form action: pardon the target
void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
  if (!getIsSigned()) {
    throw AForm::GradeTooLowException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::cout << target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
