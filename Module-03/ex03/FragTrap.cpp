#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << GREEN "FragTrap default constructor called" RESET << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << GREEN "FragTrap constructor called" RESET << std::endl;
    this->name = name;
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
    std::cout << GREEN "FragTrap copy constructor called" RESET << std::endl;
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << GREEN "FragTrap assignation operator called" RESET << std::endl;
    if (this == &fragTrap)
        return *this;
    this->name = fragTrap.name;
    this->hit_point = fragTrap.hit_point;
    this->energy_point = fragTrap.energy_point;
    this->attack_damage = fragTrap.attack_damage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED "FragTrap destructor called" RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " high fives guys" << std::endl;
}