#ifndef MATTERIASOURCE_HPP
#define MATTERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *_source[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria *m);
        virtual AMateria *createMateria(std::string const &type);
};

#endif