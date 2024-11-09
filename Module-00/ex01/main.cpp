#include "phonebook.hpp"
#include "contact.hpp"

void displayPrompt()
{
    std::cout << GREEN "Welcome to the PhoneBook!" RESET<< std::endl;
    std::cout << "valid command: " YELLOW ADD", " SEARCH ", " RESET "or " YELLOW EXIT RESET ", " YELLOW CTRLD RESET << std::endl;
}

std::string getUserCommand()
{
    std::string command;

    std::cout << "> ";
    std::getline(std::cin, command);
    if (command == ADD || command == SEARCH || command == EXIT || std::cin.eof())
    {
        return command;
    }
    else
    {
        std::cout << RED "Invalid command Please enter a command " RESET  YELLOW ADD", " SEARCH ", " RESET "or " YELLOW EXIT RESET  ", " YELLOW CTRLD RESET << std::endl;
    }
    return (command);
}

int main()
{
    PhoneBook phonebook = PhoneBook();
    std::string cmd;

    displayPrompt();
    while (true)
    {
        cmd = getUserCommand();
        if (cmd == EXIT || std::cin.eof())
            return (0);
        else if (cmd == ADD)
            phonebook.addContact();
        else if (cmd == SEARCH)
            phonebook.searchContact();
    }
}