#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
    /* data */
public:
    FragTrap();
    ~FragTrap();
    FragTrap &operator=(const FragTrap &FragTrap);
    FragTrap(const FragTrap &fragTrap);
    FragTrap(std::string name);
    void highFivesGuys(void);
};
#endif