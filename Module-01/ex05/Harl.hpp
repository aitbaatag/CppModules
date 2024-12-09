#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <map>
class Harl
{
public:
    Harl(void);
    ~Harl(void);
    void complain( std::string level );
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    std::map<std::string, void (Harl::*)(void)> map;
};
#endif