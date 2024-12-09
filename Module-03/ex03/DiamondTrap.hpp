#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
    std::string _name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &diamondTrap);    
    DiamondTrap &operator=(const DiamondTrap &diamondTrap);
    ~DiamondTrap();

    void whoAmI();
    void attack(std::string const & target);
};
#endif