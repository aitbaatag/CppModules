#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->name = name;
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
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
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " high fives guys" << std::endl;
}