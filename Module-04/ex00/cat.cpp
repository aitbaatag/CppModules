#include "cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "Cat Constructor" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat Destructor" << std::endl;
}

Cat::Cat(const Cat &copy) {
    this->type = copy.type;
    std::cout << "Cat Copy Constructor" << std::endl;
}

Cat &Cat::operator = (const Cat &copy) {
    std::cout << "Cat Assignment Operator" << std::endl;
    this->type = copy.type;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}