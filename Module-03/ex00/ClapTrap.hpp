#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap
{
private:
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
    void attack(std::string const & target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
#endif