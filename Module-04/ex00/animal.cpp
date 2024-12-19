#include "animal.hpp"


Animal::Animal() {
    std::cout << "Animal Constructor" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal Destructor" << std::endl;
}

Animal::Animal(const Animal &copy) {
    *this = copy;
}

Animal &Animal::operator = (const Animal &copy) {
    this->type = copy.type;
    return *this;
}

std::string Animal::getType() const {
    return this->type;
}

void Animal::makeSound() const {
    std::cout << "Animal Sound" << std::endl;
}