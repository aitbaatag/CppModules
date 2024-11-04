#include "ReadF"

Read::Read(std::string filename)
{
    reader(filename, std::ios::in);
}
Read::~Read(std::string filename)
{
}
std::ifstream Read::getReader(void)
{
    return (reader);
}