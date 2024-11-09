#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

#define SEARCH "SEARCH"
#define ADD "ADD"
#define EXIT "EXIT"
#define CTRLD "CTRL+D"
#define GREEN "\e[1;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define RED "\e[1;31m"
#define RESET "\e[0m"

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