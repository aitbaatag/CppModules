#include "phonebook.hpp"
#include "contact.hpp"

void displayPrompt()
{
    std::cout << "Welcome to the PhoneBook!" << std::endl;
    std::cout << "Please enter a command: ADD, SEARCH, or EXIT." << std::endl;
}

std::string getUserCommand()
{
    std::string command;

    displayPrompt();
    std::cout << "> ";
    std::getline(std::cin, command);
    if (command == ADD || command == SEARCH || command == EXIT)
    {
        return command;
    }
    else
    {
        std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
    }
    return (NULL);
}

int main()
{
    PhoneBook phonebook = PhoneBook();
    std::string cmd;

    while (true)
    {
        cmd = getUserCommand();
        if (cmd == EXIT)
            return (0);
        else if (cmd == ADD)
            phonebook.addContact();
        else if (cmd == SEARCH)
            phonebook.searchContact();
    }
}