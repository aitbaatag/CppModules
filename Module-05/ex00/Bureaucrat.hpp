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
  Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  ~Bureaucrat();

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
