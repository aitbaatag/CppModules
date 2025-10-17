#include "ShrubberyCreationForm.hpp"
#include <string>

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

// form action: create a file name <target>_shrubbery and write ASCII trees to
// it

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
  if (!getIsSigned()) {
    throw AForm::GradeTooLowException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  }

  std::string filename = target + "_shrubbery";
  std::ofstream outFile(filename.c_str());
  if (!outFile) {
    std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
    return;
  }

  outFile << "       _-_\n"
             "    /~~   ~~\\\n"
             " /~~         ~~\\\n"
             "{               }\n"
             " \\  _-     -_  /\n"
             "   ~  \\\\ //  ~\n"
             "_- -   | | _- _\n"
             "  _ -  | |   -_\n"
             "      // \\\\\n";

  outFile.close();
}
