#include "Zombie.hpp"

int main(void)
{
    Zombie* zombie = newZombie("Zombie");
    zombie->announce();
    randomChump("StackZombie");
    delete zombie;
    return (0);
}