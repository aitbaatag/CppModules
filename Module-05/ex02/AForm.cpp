#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign),
      gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    isSigned = other.isSigned;
  }
  return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return name; }

bool AForm::getIsSigned() const { return isSigned; }

int AForm::getGradeToSign() const { return gradeToSign; }

int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > gradeToSign)
    throw GradeTooLowException();
  else if (isSigned == false) {
    isSigned = true;
    std::cout << bureaucrat.getName() << " signed " << name << std::endl;
  } else
    std::cout << name << " is already signed." << std::endl;
}
const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}
const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}
std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form: " << form.getName()
     << ", isSigned: " << (form.getIsSigned() ? "true" : "false")
     << ", gradeToSign: " << form.getGradeToSign()
     << ", gradeToExecute: " << form.getGradeToExecute();
  return os;
}
