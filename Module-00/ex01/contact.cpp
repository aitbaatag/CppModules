#include "contact.hpp"
bool Contact::isEmpty()
{
    return firstName.empty() && lastName.empty() && nickname.empty() &&
           phoneNumber.empty() && darkestSecret.empty();
}
void Contact::setFirstName(std::string name)
{
    firstName = name;
}
void Contact::setLastName(std::string name)
{
    lastName = name;
}
void Contact::setNickname(std::string name)
{
    nickname = name;
}
void Contact::setPhoneNumber(std::string number)
{
    phoneNumber = number;
}
void Contact::setDarkestSecret(std::string secret)
{
    darkestSecret = secret;
}
std::string Contact::getFirstName()
{
    return (firstName);
}
std::string Contact::getLastName()
{
    return (lastName);
}
std::string Contact::getNickname()
{
    return (nickname);
}
std::string Contact::getPhoneNumber()
{
    return (phoneNumber);
}
std::string Contact::getDarkestSecret()
{
    return (darkestSecret);
}