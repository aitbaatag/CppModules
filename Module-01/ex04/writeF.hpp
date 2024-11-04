#ifndef WRITEF_HPP
#define WRITEF_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class WriteF
{
    private:
        std::ofstream writer;
    public:
        WriteF(std::string filename);
        ~WriteF(void);
        std::ofstream getWriter(void);
}
#endif