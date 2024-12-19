#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        ~Cat();
        Cat(const Cat &copy);
        Cat &operator = (const Cat &copy);
        void makeSound() const;
};

#endif