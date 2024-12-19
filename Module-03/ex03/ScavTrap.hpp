#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
private:
    /* data */
public:
    ~ScavTrap();
    ScavTrap &operator=(const ScavTrap &scavTrap);
    ScavTrap(const ScavTrap &scavTrap);
    ScavTrap(std::string name);
    ScavTrap();
    void attack(std::string const &target);
    void guardGate();

};
#endif