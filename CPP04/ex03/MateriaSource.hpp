#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
  private:
    AMateria* _materia[4];

  public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    ~MateriaSource();

    void      learnMateria(AMateria* m);
    AMateria* createMateria(std::string const& type);

    MateriaSource& operator=(const MateriaSource& other);
};

#endif
