#include "StreamWriter.hpp"

StreamWriter::StreamWriter(std::string filename)
{
    writer.open(filename.c_str());
    if (!writer.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        exit(1);
    }
}
StreamWriter::~StreamWriter(void)
{
    if (writer.is_open())
        writer.close();
}
std::ofstream& StreamWriter::getWriter(void)
{
    return (writer);
}