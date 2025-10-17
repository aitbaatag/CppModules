#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;
class Form {
private:
  const std::string name;
  bool isSigned;
  const int gradeToSign;    // what grade do you need to sign the form
  const int gradeToExecute; // what grade do you need to execute the form

public:
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  const std::string &getName() const;
  bool getIsSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
