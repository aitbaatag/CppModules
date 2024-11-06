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
    void Filter( std::string level );
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
private:
    std::map<std::string, int> map;
};
#endif