#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

#define SEARCH "SEARCH"
#define ADD "ADD"
#define EXIT "EXIT"

class PhoneBook
{
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    void addContact(void);
    void searchContact();
};

#endif