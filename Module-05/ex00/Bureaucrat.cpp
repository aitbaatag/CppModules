#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name) {
  *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
  if (this != &other) {
    this->grade = other.grade;
  }
  return *this;
}
Bureaucrat::~Bureaucrat() {
  // Destructor
}

void Bureaucrat::incrementGrade() {
  if (this->grade <= 1)
    throw GradeTooHighException();
  this->grade--;
}
void Bureaucrat::decrementGrade() {
  if (this->grade >= 150)
    throw GradeTooLowException();
  this->grade++;
}
const std::string &Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high!";
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low!";
}
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat) {
  out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return out;
}
