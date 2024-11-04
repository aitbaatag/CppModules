#include "writeF.hpp"

WriteF::WriteF(std::string filename)
{
    writer.open(filename.c_str());
    if (!writer.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit(1);
    }
}
WriteF::~WriteF(std::string filename)
{
    writer.close();
}
std::ofstream WriteF::getWriter(void)
{
    return (writer);
}