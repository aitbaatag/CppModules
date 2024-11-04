#ifndef WRITEF_HPP
#define WRITEF_HPP

#include <iostream>
#include <string>
#include <fstream>

class WriteF
{
    private:
        std::ofstream writer;
        std::string newname;
    public:
        WriteF(std::string filename);
        ~WriteF(void);
        std::ofstream getWriter(void);
}
#endif