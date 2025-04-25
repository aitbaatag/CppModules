#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
