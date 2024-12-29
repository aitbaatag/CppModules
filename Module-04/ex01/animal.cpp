#include "animal.hpp"


Animal::Animal() {
    std::cout << GREEN "Animal Constructor" RESET << std::endl;
}

Animal::~Animal() {
    std::cout << RED "Animal Destructor" RESET << std::endl;
}

Animal::Animal(const Animal &copy) {
    this->type = copy.type;
    std::cout << GREEN "Animal Copy Constructor" RESET << std::endl;
}

Animal &Animal::operator = (const Animal &copy) {
    std::cout << GREEN "Animal Assignment Operator" RESET << std::endl;
    if (this == &copy)
        return *this;
    this->type = copy.type;
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "Animal Sound" << std::endl;
}