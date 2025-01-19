#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap")
{
    std::cout << GREEN "DiamondTrap default constructor called" RESET << std::endl;
    this->name = "default";
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_trap")
{
    std::cout << GREEN "DiamondTrap constructor called" RESET << std::endl;
    this->name = name;
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
{
    if (this == &diamondTrap)
        return;
    *this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap)
{
    std::cout << GREEN "DiamondTrap assignation operator called" RESET << std::endl;
    this->_name = diamondTrap._name;
    this->name = diamondTrap.name;
    this->hit_point = diamondTrap.hit_point;
    this->energy_point = diamondTrap.energy_point;
    this->attack_damage = diamondTrap.attack_damage;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << RED "DiamondTrap destructor called" RESET << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->name << std::endl;
}

void DiamondTrap::attack(std::string const &target)
{
    ScavTrap::attack(target);
}