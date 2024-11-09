#include "phonebook.hpp"

void displayContactRow(std::string firstName,
                       std::string lastName,
                       std::string nickname,
                       std::string phoneNumber,
                       std::string darkestSecret)
{
    std::cout << " | " << std::setw(10) << std::right << firstName.substr(0, 9) + (firstName.length() > 10 ? "." : "")
              << " | " << std::setw(10) << std::right << lastName.substr(0, 9) + (lastName.length() > 10 ? "." : "")
              << " | " << std::setw(10) << std::right << nickname.substr(0, 9) + (nickname.length() > 10 ? "." : "")
              << " | " << std::setw(10) << std::right << phoneNumber.substr(0, 9)
              << " | " << std::setw(10) << std::right << darkestSecret.substr(0, 9) + (darkestSecret.length() > 10 ? "." : "")
              << " |" << std::endl;
}

PhoneBook::PhoneBook()
{
    index = 0;
}
std::string getInput(std::string prompt)
{
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
    while (input.empty())
    {
        if (std::cin.eof())
            exit(0);
        std::cout << RED "This field cannot be empty. Please try again." RESET << std::endl;
        std::cout << prompt;
        std::getline(std::cin, input);
    }
    return input;
}
void addContactInfo(Contact &contact)
{
    contact.setFirstName(getInput("Enter First Name: "));
    contact.setLastName(getInput("Enter Last Name: "));
    contact.setNickname(getInput("Enter Nickname: "));
    while (true)
    {
        contact.setPhoneNumber(getInput("Enter Phone Number: "));
        if (contact.getPhoneNumber().find_first_not_of("0123456789") && contact.getPhoneNumber().length() == 10)
            break;
        std::cout << RED "Invalid phone number. Please try again." RESET << std::endl;
    }
    contact.setDarkestSecret(getInput("Enter Darkest Secret: "));
    std::cout << GREEN "Contact added successfully!" RESET << std::endl;
}
void PhoneBook::addContact(void)
{
    Contact newContact = Contact();
    addContactInfo(newContact);
    contacts[index] = newContact;
    index = (index + 1) % 8;
}
void PhoneBook::searchContact()
{
    int i;
    int size;

    size = sizeof(contacts) / sizeof(contacts[0]);
    i = 0;
    if (contacts[0].isEmpty())
    {
        std::cout << YELLOW "The phonebook is empty." RESET << std::endl;
        return;
    }
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "| " << std::setw(10) << std::right << "index";
    displayContactRow("First Name", "Last Name", "Nickname", "Phone Number", "Darkest Secret");
    while (i < size && !contacts[i].isEmpty())
    {
        std::cout << "| " << std::setw(10) << std::right << i + 1;
        displayContactRow(contacts[i].getFirstName(),
                          contacts[i].getLastName(),
                          contacts[i].getNickname(),
                          contacts[i].getPhoneNumber(),
                          contacts[i].getDarkestSecret());
        i++;
    }
    std::string input = getInput("Enter the index (1 - 9) of the contact to view in detail: ");
    if (input.length() > 1 || input.empty() || input.find_first_not_of("0123456789") != std::string::npos || input[0] - '0' > index)
    {
        std::cout << RED "Invalid index, please try again." RESET << std::endl;
        return;
    }
    int n = input[0] - '0';
    if (n == 0)
    {
        std::cout << RED "Invalid index, please try again." RESET << std::endl;
    }
    else
    {
        std::cout << "---------------------------------------------" << std::endl;
        Contact curr_contact = contacts[n - 1];
        std::cout << "Details for contact " << n << ":" << std::endl;
        std::cout << "First Name: " << curr_contact.getFirstName() << std::endl;
        std::cout << "Last Name: " << curr_contact.getLastName() << std::endl;
        std::cout << "Nickname: " << curr_contact.getNickname() << std::endl;
        std::cout << "Phone Number: " << curr_contact.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << curr_contact.getDarkestSecret() << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
    }
}