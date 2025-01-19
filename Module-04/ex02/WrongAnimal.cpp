#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    this->type = copy.type;
    std::cout << "WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &copy) {
    std::cout << "WrongAnimal Assignment Operator" << std::endl;
    this->type = copy.type;
    return *this;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal Sound" << std::endl;
}