
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
private:
  const std::string name;
  int grade;

public:
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);            // copy constructor
  Bureaucrat &operator=(const Bureaucrat &other); // copy assignment operator
  ~Bureaucrat();                                  // destructor
  // getters
  const std::string &getName() const;
  int getGrade() const;
  // increment and decrement
  void incrementGrade();
  void decrementGrade();
  // Exceptions
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  // Add signForm method
  void signForm(AForm &form) const;

  // new method to execute a form
  void executeForm(const AForm &form) const;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
