#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  if (!getIsSigned())
    throw AForm::GradeTooLowException();
  if (executor.getGrade() > getGradeToExecute())
    throw AForm::GradeTooLowException();

  std::ofstream outfile(target + "_shrubbery");
  if (!outfile) {
    std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
    return;
  }

  outfile.close();
}
