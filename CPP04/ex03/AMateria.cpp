
#include "AMateria.hpp"

#include "ICharacter.hpp"
#include "Logger.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : _type(type)
{
    Logger::printLog("AMateria constructor called");
}

AMateria::AMateria(AMateria const& other)
{
    Logger::printLog("AMateria copy constructor called");
    *this = other;
}

AMateria::~AMateria()
{
    Logger::printLog("AMateria destructor called");
}

const std::string& AMateria::getType() const
{
    return _type;
}

// TODO: implement this function
void AMateria::use(ICharacter& target)
{
    Logger::printLog("AMateria use function called");
    std::cout << "* uses AMateria on " << target.getName() << " *" << std::endl;
}

AMateria& AMateria::operator=(AMateria const& other)
{
    Logger::printLog("AMateria assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}
