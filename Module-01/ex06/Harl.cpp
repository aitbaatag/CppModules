#include "Harl.hpp"

Harl::Harl(void) 
{
    map["DEBUG"] = 1;
    map["INFO"] = 2;
    map["WARNING"] = 3;
    map["ERROR"] = 4;
}
Harl::~Harl(void)
{
}
void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ] " << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ] " << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ] " << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::Filter(std::string Slevel)
{
    int level = map[Slevel];

    std::cout << "Filtering level: " << Slevel << std::endl;
    switch (level)
    {
    case 1:
        Harl::debug();
        break;
    case 2:
        Harl::info();
        break;
    case 3:
        Harl::warning();
        break;
    case 4:
        Harl::error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        break;
    }
}