#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        Harl harl;
        harl.Filter(argv[1]);
    }
    else
    {
        std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
    }
    return 0;
}
