
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << "\n=== Attempt signing forms ===\n";
    alice.signForm(shrub); // Should fail
    bob.signForm(shrub);   // Should succeed
    bob.signForm(robot);   // Should succeed
    bob.signForm(pardon);  // Should succeed

    std::cout << "\n=== Attempt executing forms ===\n";
    alice.executeForm(shrub); // Should fail
    bob.executeForm(shrub);   // Should succeed
    bob.executeForm(robot);   // Should succeed (50% chance fail)
    bob.executeForm(pardon);  // Should succeed

    std::cout << "\n=== Test exceptions ===\n";
    PresidentialPardonForm invalidForm("X");
    Bureaucrat junior("Junior", 150);
    junior.executeForm(invalidForm); // Not signed, should throw
    junior.signForm(invalidForm);    // Grade too low, should throw

  } catch (std::exception &e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
  }

  return 0;
}
