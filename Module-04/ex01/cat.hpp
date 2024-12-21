#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat &copy);
        Cat &operator = (const Cat &copy);
        void makeSound() const;
        std::string getIdea(int index) const;
        void setIdea(int index, const std::string &idea);
        void setIdea(int index, const std::string &idea) const;
};

#endif