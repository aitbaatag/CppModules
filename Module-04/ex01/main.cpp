#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"


int main()
{
    const Dog *dog = new Dog();
    const Cat *cat = new Cat();
    

    for (int i = 0; i < 10; i++)
    {
        dog->setIdea(i, dog->getType() + " Idea ");
        cat->setIdea(i, cat->getType() + " Idea ");
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << dog->getIdea(i) << std::endl;
        std::cout << cat->getIdea(i) << std::endl;
    }

    delete dog;
    delete cat;
    return 0;
}