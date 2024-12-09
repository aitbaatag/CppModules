#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scavTrap;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    this->name = scavTrap.name;
    this->hit_point = scavTrap.hit_point;
    this->energy_point = scavTrap.energy_point;
    this->attack_damage = scavTrap.attack_damage;
    return *this;
}
ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}
void ScavTrap::attack(std::string const &target)
{
    std::cout << "ScavTrap " << this->name << " attack " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
}
ScavTrap::ScavTrap(std::string name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->name = name;
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap have enterred in Gate keeper mode" << std::endl;
}