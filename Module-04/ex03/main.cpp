#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice()); // learnMateria() will store the materia in the first available slot
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");
    AMateria *tmp;
    tmp = src->createMateria("ice"); // createMateria() will return a new materia (Ice or Cure) already learned
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->unequip(0); // unequip() will remove the materia from the inventory
    me->use(0, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}