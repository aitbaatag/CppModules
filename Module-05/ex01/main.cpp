#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Bureaucrat b1("Alice", 50);
    Bureaucrat b2("Bob", 150);
    Form f1("Form1", 100, 50);
    Form f2("Form2", 0, 50);   // This will throw an exception
    Form f3("Form3", 50, 200); // This will also throw an exception

    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    b1.signForm(f1);
    b2.signForm(f1);

  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
