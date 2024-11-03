#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;

    if (N <= 0)
        return 0;
    Zombie* horde = new Zombie[N]; 
    i = 0;
    while (i < N)
    {
        horde[i].setName(name);
        i++;
    }
    return horde;
}