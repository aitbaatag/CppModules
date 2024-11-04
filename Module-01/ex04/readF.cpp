#include "readF.hpp"

ReadF::ReadF(std::string filename)
{
    reader.open(filename.c_str());
    if (!reader.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit(1);
    }
}
ReadF::~ReadF(void)
{
    reader.close();
}
std::ifstream ReadF::getReader(void)
{
    return (reader);
}