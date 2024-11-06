#include "Harl.hpp"

Harl::Harl(void) 
{
    map["DEBUG"] = 0;
    map["INFO"] = 1;
    map["WARNING"] = 2;
    map["ERROR"] = 3;
}
Harl::~Harl(void)
{
}
void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::Filter(std::string Slevel)
{
    int level = map[Slevel];

    std::cout << "Filtering level: " << Slevel << std::endl;
    switch (level)
    {
    case 0:
        Harl::debug();
        break;
    case 1:
        Harl::info();
        break;
    case 2:
        Harl::warning();
        break;
    case 3:
        Harl::error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}