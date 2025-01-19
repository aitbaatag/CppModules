#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

struct AllMateria
{
    AMateria *materia;
    AllMateria *next;
};

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria *_inventory[4];
        AllMateria *_materiaLeft;
    public:
        Character(std::string name);
        Character(const Character &other);
        Character &operator=(const Character &other);
        virtual ~Character();
        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
        void deleteInventory();
        void addMateriaLeft(AMateria *m);
};

#endif