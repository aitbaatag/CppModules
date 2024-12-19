#include "dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    std::cout << "Dog Constructor" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog Destructor" << std::endl;
}

Dog::Dog(const Dog &copy) {
    *this = copy;
}

Dog &Dog::operator = (const Dog &copy) {
    this->type = copy.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}