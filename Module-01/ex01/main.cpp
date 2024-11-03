#include "Zombie.hpp"

int main(void)
{
    int i;

    i = 0;
    Zombie* horde = zombieHorde(4,"Zombie");
    while (i < 4)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
    return (0);
}