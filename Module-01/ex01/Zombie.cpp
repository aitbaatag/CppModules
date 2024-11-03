#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::Zombie(void)
{
    this->name = "Unnamed";
}

Zombie::~Zombie(void)
{
    std::cout << name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name)
{
    this->name = name;
}