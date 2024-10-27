#include <iostream>
int main(int argc, char **argv)
{
    char *arg;
    char ch;

    if (argc > 1)
    {
        argv++;
        while (*argv)
        {
            arg = *argv;
            while (*arg)
            {
                ch = *arg;
                if (ch >= 'a' && ch <= 'z')
                    ch -= 32;
                std::cout << ch;
                arg++;
            }
            argv++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}