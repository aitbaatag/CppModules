#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << GREEN "ClapTrap default constructor called" RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << GREEN "ClapTrap constructor called" RESET << std::endl;
    this->name = name;
    this->hit_point = 10;
    this->energy_point = 10;
    this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    *this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    this->name = claptrap.name;
    this->hit_point = claptrap.hit_point;
    this->energy_point = claptrap.energy_point;
    this->attack_damage = claptrap.attack_damage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << RED "ClapTrap destructor called" RESET << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
    std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
    if (this->hit_point < 0)
        this->hit_point = 0;
    this->hit_point -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " repaired " << amount << " points of damage!" << std::endl;
    this->hit_point += amount;
}
