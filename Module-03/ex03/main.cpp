#include "DiamondTrap.hpp"
int main()
{
    DiamondTrap diamondTrap("diamond");
    diamondTrap.whoAmI();
    diamondTrap.attack("target");
    diamondTrap.takeDamage(10);
    diamondTrap.beRepaired(10);
    diamondTrap.highFivesGuys();
    return 0;
}