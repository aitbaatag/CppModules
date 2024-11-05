#include "Harl.hpp"

Harl::Harl(void) 
{
    map["DEBUG"] = &Harl::debug;
    map["INFO"] = &Harl::info;
    map["WARNING"] = &Harl::warning;
    map["ERROR"] = &Harl::error;
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

void Harl::complain(std::string level)
{
    FunPtr curr_function = map[level];
    if (curr_function)
    {
        (this->*curr_function)();
    }
    else
    {
        std::cout << "Invalid level!" << std::endl;
    }
}