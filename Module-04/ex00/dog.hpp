#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        ~Dog();
        Dog(const Dog &copy);
        Dog &operator = (const Dog &copy);
        void makeSound() const;
};

#endif