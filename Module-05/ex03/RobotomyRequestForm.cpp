#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy Request", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// form action: make some drilling noises, and inform that the target has been
void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
  if (!getIsSigned()) {
    throw AForm::GradeTooLowException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::cout << "Bzzzzzz... Vrrrrrr... (drilling noises)" << std::endl;

  // 50% chance of success
  if (rand() % 2) {
    std::cout << target << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "Robotomy failed on " << target << "." << std::endl;
  }
}
