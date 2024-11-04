#ifndef READF_HPP
#define READF_HPP

#include <iostream>
#include <string>
#include <fstream>

class ReadF
{
    private:
        std::ifstream reader;
    public:
        ReadF(std::string filename);
        ~ReadF(void);
        std::ifstream getReader(void);
}
#endif