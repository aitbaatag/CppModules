#include "phonebook.hpp"
void displayContactRow(Contact contact, int index)
{
    std::cout << "| " << std::setw(10) << std::right << index
              << " | " << std::setw(10) << std::right << contact.getFirstName()
              << " | " << std::setw(10) << std::right << contact.getLastName()
              << " | " << std::setw(10) << std::right << contact.getNickname()
              << " | " << std::setw(10) << std::right << contact.getPhoneNumber()
              << " |" << std::endl;
}
PhoneBook::PhoneBook()
{
    index = 0;
}
std::string getInput(const std::string prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    if (input.empty())
    {
        std::cout << "This field cannot be empty. Please try again." << std::endl;
    }
    return input;
}
bool isValidNumber(std::string input)
{
    for (char c : input)
    {
        if (!std::isdigit(c) && c != '-')
        {
            return false;
        }
    }
    return !input.empty();
}
void addContactInfo(Contact &contact)
{
    contact.setFirstName(getInput("Enter First Name: "));
    contact.setLastName(getInput("Enter Last Name: "));
    contact.setNickname(getInput("Enter Nickname: "));
    contact.setPhoneNumber(getInput("Enter Phone Number: "));
    contact.setDarkestSecret(getInput("Enter Darkest Secret: "));
}
void PhoneBook::addContact(void)
{
    Contact newContact = Contact();
    addContactInfo(newContact);
    index = (index + 1) % 8;
    contacts[index] = newContact;
    index++;
}
void PhoneBook::searchContact()
{
    int i;

    i = 0;
    if (index == 0)
    {
        std::cout << "The phonebook is empty." << std::endl;
        return;
    }
    std::cout << "|   Index  | First Name | Last Name | Nickname |   Phone  | Darkest Secret" << std::endl;
    while (i < index)
    {
        displayContactRow(contacts[i], i + 1);
        i++;
    }
    std::string input = getInput("Enter the index of the contact to view in detail: ");
    int n = std::stoi(input);
    if (!n || n >= 8)
        std::cout << "Invalid index, please try again." << std::endl;
    else
    {
        Contact curr_contact = contacts[n - 1];
        std::cout << "Details for contact " << n << ":" << std::endl;
        std::cout << "First Name: " << curr_contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << curr_contact.getLastName() << std::endl;
        std::cout << "Nickname: " << curr_contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << curr_contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << curr_contact.getDarkestSecret() << std::endl;
    }
}