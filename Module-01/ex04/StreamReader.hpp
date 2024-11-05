#ifndef STREAMREADER_HPP
#define STREAMREADER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class StreamReader
{
    private:
        std::ifstream reader;
    public:
        StreamReader(std::string filename);
        ~StreamReader(void);
        std::ifstream& getReader(void);
};
#endif