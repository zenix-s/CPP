
#include "MateriaSource.hpp"

#include "Logger.hpp"
#include <string>

MateriaSource::MateriaSource()
{
    Logger::printLog("MateriaSource constructor called");
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    Logger::printLog("MateriaSource copy constructor called");
    *this = other;
}

MateriaSource::~MateriaSource()
{
    Logger::printLog("MateriaSource destructor called");
    for (int i = 0; i < 4; i++)
        delete _materia[i];
}

void MateriaSource::learnMateria(AMateria* materia)
{
    Logger::printLog("MateriaSource learnMateria function called");

    if (!materia)
    {
        Logger::printLog("Invalid materia provided");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] == NULL)
        {
            _materia[i] = materia;
            return;
        }
    }
    Logger::printLog("No empty slot available to learn materia");
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    Logger::printLog("MateriaSource createMateria function called");
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return _materia[i]->clone();
    }
    Logger::printLog("No materia of the requested type found");
    return NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    Logger::printLog("MateriaSource assignment operator called");

    if (this == &other)
        return *this;

    for (int i = 0; i < 4; i++)
    {
        delete _materia[i];
        if (other._materia[i])
            _materia[i] = other._materia[i]->clone();
        else
            _materia[i] = NULL;
    }
    return *this;
}
