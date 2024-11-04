#ifndef READF_HPP
#define READF_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class ReadF
{
    private:
        std::ifstream reader;
    public:
        ReadF(std::string filename);
        ~ReadF(void);
        std::ifstream getReader(void);
};
#endif