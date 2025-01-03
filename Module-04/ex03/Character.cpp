#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &other) {
    *this = other;
}

Character &Character::operator=(const Character &other) {
    if (this == &other)
        return *this;
    _name = other._name;
    for (int i = 0; i < 4; i++)
        _inventory[i] = other._inventory[i];
    return *this;
}

Character::~Character() {
    for (int i = 0; i < 4; i++)
        if (_inventory[i])
            delete _inventory[i];
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria *m) {
    for (int i = 0; i < 4; i++)
        if (!_inventory[i]) {
            _inventory[i] = m;
            break;
        }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx >= 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}
