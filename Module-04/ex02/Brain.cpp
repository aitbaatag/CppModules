#include "Brain.hpp"

Brain::Brain()
{
    std::cout << GREEN "Brain constructed" RESET << std::endl;
}
Brain::Brain(const Brain& other) {
    std::cout << GREEN "Brain copy constructed" RESET << std::endl;
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}
Brain::~Brain() {
    std::cout << RED "Brain destructed!" RESET << std::endl;
}

void Brain::setIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
    else
        std::cout << RED "Invalid index" RESET << std::endl;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return RED "Invalid index" RESET;
}