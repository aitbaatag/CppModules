#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "WrongCat Constructor" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) {
    this->type = copy.type;
    std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat &WrongCat::operator = (const WrongCat &copy) {
    std::cout << "WrongCat Assignment Operator" << std::endl;
    this->type = copy.type;
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}
