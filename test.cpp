#include <iostream>
#include <string>
#include <iomanip>
#include <iostream>
#include <sstream>

int main()
{
    std::cout << "enter number " ;
    std::string str;
    std::cin >> str;
    // std::getline(std::cin, str);
    std::cout << "you entered " << "[" << std::setw(40) << std::right << str << "]"<< std::endl;
}