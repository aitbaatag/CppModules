#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    ClapTrap clap("Clappy");
    clap.attack("Target A");
    clap.takeDamage(3);
    clap.beRepaired(5);
    std::cout << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Target B");
    scav.takeDamage(10);
    scav.beRepaired(20);
    scav.guardGate();

    return 0;
}
