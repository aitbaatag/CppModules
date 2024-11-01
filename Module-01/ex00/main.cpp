#include "Zombie.h"

int mian(void)
{
    Zombie* zombie = newZombie("Zombie");
    zombie->announce();
    randomChump("StackZombie");
    delete zombie;
    return (0);
}