#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat b1("John", 1);
    Bureaucrat b2("Doe", 150);
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;

    b1.incrementGrade();
    std::cout << b1 << std::endl;

    b2.decrementGrade();
    std::cout << b2 << std::endl;

    Bureaucrat b3(b1);
    std::cout << b3 << std::endl;

    Bureaucrat b4 = b2;
    std::cout << b4 << std::endl;

  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
