#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog &copy);
        Dog &operator = (const Dog &copy);
        void makeSound() const;
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string &idea);
        void setIdea(int index, const std::string &idea) const;
};

#endif