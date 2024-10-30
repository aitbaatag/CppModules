#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    void setFirstName(std::string name);
    void setLastName(std::string name);
    void setNickname(std::string name);
    void setPhoneNumber(std::string number);
    void setDarkestSecret(std::string secret);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
    bool isEmpty();
};

#endif
