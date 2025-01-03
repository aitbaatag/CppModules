#include "animal.hpp"

Animal::Animal() {
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
    type = animal.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal){
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &animal)
        type = animal.type;
    return *this;
}

std::string Animal::getType() const{
    return type;
}

void Animal::makeSound() const{
    std::cout << "Animal sound" << std::endl;
}
