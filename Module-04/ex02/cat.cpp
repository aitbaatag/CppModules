#include "cat.hpp"

Cat::Cat() {
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << RED "Memory allocation failed" RESET << std::endl;
        exit(1);
    }
    this->type = "Cat";
    std::cout << GREEN "Cat Constructor" RESET << std::endl;
}

Cat::~Cat() {
    delete this->brain;
    std::cout << RED "Cat Destructor" RESET << std::endl;
}

Cat::Cat(const Cat &copy) {
    this->type = copy.type;

    if (this->brain != NULL)
        delete this->brain;
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << RED "Memory allocation failed" RESET << std::endl;
        exit(1);
    }
    *this->brain = *copy.brain;
    std::cout << GREEN "Cat Copy Constructor" RESET << std::endl;
}

Cat &Cat::operator = (const Cat &copy) {
    std::cout << GREEN "Cat Assignment Operator" RESET << std::endl;
    this->type = copy.type;
    if (this->brain != NULL)
        delete this->brain;
    this->brain = new Brain();
    if (this->brain == NULL)
    {
        std::cout << RED "Memory allocation failed" RESET << std::endl;
        exit(1);
    }
    *this->brain = *copy.brain;
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow" << std::endl;
}

std::string Cat::getIdea(int index) const {
    return this->brain->getIdea(index);
}

void Cat::setIdea(int index, const std::string &idea) {
    this->brain->setIdea(index, idea);
}

void Cat::setIdea(int index, const std::string &idea) const {
    this->brain->setIdea(index, idea);
}