#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    _materiaLeft = NULL;
}

Character::Character(const Character &other) {
    *this = other;
}

Character &Character::operator=(const Character &other) {
    if (this == &other)
        return *this;
    _name = other._name;
    // deep copy
    for (int i = 0; i < 4; i++) {
        if (_inventory[i])
            delete _inventory[i];
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (_inventory[i])
            delete _inventory[i];
    deleteInventory();
    std::cout << "character name: " << _name << " destructor called" << std::endl;
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria *m) { // means to prepare (a weapon or piece of equipment) for use
    for (int i = 0; i < 4; i++)
        if (!_inventory[i]) {
            _inventory[i] = m;
            break;
        }
}

void Character::unequip(int idx) { // means to remove (a weapon or piece of equipment) from use
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    addMateriaLeft(_inventory[idx]);
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}

void Character::deleteInventory() {
    AllMateria *tmp;
    while (_materiaLeft) {
        tmp = _materiaLeft;
        _materiaLeft = _materiaLeft->next;
        delete tmp->materia;
        delete tmp;
    }
}

void Character::addMateriaLeft(AMateria *m) {
    AllMateria *newMateria = new AllMateria;
    newMateria->materia = m;
    newMateria->next = _materiaLeft;
    _materiaLeft = newMateria;
}