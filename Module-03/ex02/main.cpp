#include "FragTrap.hpp"
int main()
{
    FragTrap frag("Fraggy");
    frag.attack("Target C");
    frag.takeDamage(10);
    frag.beRepaired(20);
    frag.highFivesGuys();
    return 0;
}