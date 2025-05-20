#include "Character.hpp"

#include "Logger.hpp"
#include <string>

Character::Character(std::string const& name) : _name(name)
{
    Logger::printLog("Character constructor called");
    for (int i = 0; i < 4; i++)
        _materia[i] = NULL;
}

Character::Character(Character const& other)
{
    Logger::printLog("Character copy constructor called");
    *this = other;
}

Character::~Character()
{
    Logger::printLog("Character destructor called");
    for (int i = 0; i < 4; i++)
        delete _materia[i];
}

std::string const& Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* materia)
{
    Logger::printLog("Character equip function called");
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] == NULL)
        {
            _materia[i] = materia;
            return;
        }
    }

    Logger::printLog("No empty slot available to equip materia");
}

void Character::unequip(int idx)
{
    Logger::printLog("Character unequip function called");
    if (idx < 0 || idx >= 4)
    {
        Logger::printLog("Invalid index for unequip");
        return;
    }
    _materia[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    Logger::printLog("Character use function called");
    if (idx < 0 || idx >= 4)
    {
        Logger::printLog("Invalid index for use");
        return;
    }
    if (_materia[idx] == NULL)
    {
        Logger::printLog("No materia equipped at this index");
        return;
    }
    _materia[idx]->use(target);
}

Character& Character::operator=(Character const& other)
{
    Logger::printLog("Character assignment operator called");
    if (this == &other)
        return *this;

    _name = other._name;
    for (int i = 0; i < 4; i++)
    {
        if (other._materia[i])
            _materia[i] = other._materia[i]->clone();
        else
            _materia[i] = NULL;
    }

    return *this;
}
