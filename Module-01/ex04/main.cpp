#include <iostream>
#include <string>
#include <fstream>

void my_replace(std::ifstream reader, std::ofstream writer, const std::string s1, const std::string s2)
{
    std::string line;

    while (std::getline(reader, line))
    {
        size_t pos = 0;

        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            writer << line.substr(0, pos);
            writer << s2;
            pos += s1.length();
            line = line.substr(pos);
            pos = 0;
        }
        writer << line << '\n';
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];

        readF readf = readF(filename);
        writeF writef = writeF(readf.getbuffer, filename);
        replace(readf.getbuffer, s1, s2);
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
    }
}