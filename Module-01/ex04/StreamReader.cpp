#include "StreamReader.hpp"

StreamReader::StreamReader(std::string filename)
{
    reader.open(filename.c_str());
    if (!reader.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit(1);
    }
}
StreamReader::~StreamReader(void)
{
    if (reader.is_open())
        reader.close();
}
std::ifstream& StreamReader::getReader(void)
{
    return (reader);
}