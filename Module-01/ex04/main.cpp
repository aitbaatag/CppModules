#include <iostream>
#include <string>

void my_replace(std::ifstream reader, std::ofstream writer std::string s1, std::string s2)
{
    std::string word;
    while (reader >> word)
    {
        if (word.compare(s1) == 0)
            writer << s2;
        else
            writer << word;
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