#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define RED "\e[1;31m"
#define RESET "\e[0m"

class ClapTrap
{
protected:
    std::string name;
    int hit_point;
    int energy_point;
    int attack_damage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &claptrap);
    ClapTrap &operator=(const ClapTrap &claptrap);
    ~ClapTrap();
    virtual void attack(std::string const & target);
    virtual void takeDamage(unsigned int amount);
    virtual void beRepaired(unsigned int amount);
};
#endif