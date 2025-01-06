#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

AMateria::AMateria() : _type("default") {}
AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria::AMateria(const AMateria &other) {
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other) {
    if (this == &other)
        return *this;
    _type = other._type;
    return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "* uses some materia on " << target.getName() << " *" << std::endl;
}

AMateria* AMateria::clone() const {
    if (_type == "ice")
        return new Ice();
    else if (_type == "cure")
        return new Cure();
    return NULL;
}
