#include "dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << RED "Memory allocation failed" RESET << std::endl;
        exit(1);
    }
    std::cout << GREEN "Dog Constructor" RESET << std::endl;
}

Dog::~Dog() {
    if (this->brain != NULL)
        delete this->brain;
    std::cout << RED "Dog Destructor" RESET << std::endl;
}

Dog::Dog(const Dog &copy) {
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << RED "Memory allocation failed" RESET << std::endl;
        exit(1);
    }
    *this->brain = *copy.brain;
    std::cout << GREEN "Dog Copy Constructor" RESET << std::endl;
    this->type = copy.type;
}

Dog &Dog::operator = (const Dog &copy) {
    std::cout << GREEN "Dog Assignment Operator" RESET << std::endl;
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << RED "Memory allocation failed" RESET << std::endl;
        exit(1);
    }
    *this->brain = *copy.brain;
    this->type = copy.type;
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof" << std::endl;
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}

void Dog::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

void Dog::setIdea(int index, const std::string &idea) const {
    brain->setIdea(index, idea);
}