#ifndef STREAMWRITER_HPP
#define STREAMWRITER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class StreamWriter
{
    private:
        std::ofstream writer;
    public:
        StreamWriter(std::string filename);
        ~StreamWriter(void);
        std::ofstream& getWriter(void);
};
#endif