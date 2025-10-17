
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
  Bureaucrat Khalid("Khalid", 1);
  Bureaucrat Hicham("Hicham", 150);

  ShrubberyCreationForm shrub("home");
  RobotomyRequestForm robot("Bender");
  PresidentialPardonForm pardon("Marvin");

  std::cout << "\n=== Attempt signing forms ===\n";
  Hicham.signForm(shrub);  // Should fail
  Khalid.signForm(shrub);  // Should succeed
  Khalid.signForm(robot);  // Should succeed
  Khalid.signForm(pardon); // Should succeed

  std::cout << "\n=== Attempt executing forms ===\n";
  Hicham.executeForm(shrub);  // Should fail
  Khalid.executeForm(shrub);  // Should succeed
  Khalid.executeForm(robot);  // Should succeed (50% chance fail)
  Khalid.executeForm(pardon); // Should succeed

  std::cout << "\n=== Test exceptions ===\n";
  PresidentialPardonForm invalidForm("X");
  Bureaucrat junior("Junior", 150);
  junior.executeForm(invalidForm); // Not signed, should throw
  junior.signForm(invalidForm);    // Grade too low, should throw

  return 0;
}
