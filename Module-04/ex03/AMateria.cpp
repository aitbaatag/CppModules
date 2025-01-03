#include "AMateria.hpp"

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
    (void)target;
}

AMateria* AMateria::clone() const {
    return new AMateria(*this);
}
