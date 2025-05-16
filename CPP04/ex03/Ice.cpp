
#include "Ice.hpp"

#include "ICharacter.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Ice::Ice() : AMateria("ice")
{
    Logger::printLog("Ice constructor called");
}

Ice::Ice(const Ice& other) : AMateria(other)
{
    Logger::printLog("Ice copy constructor called");
    *this = other;
}

Ice::~Ice()
{
    Logger::printLog("Ice destructor called");
}

AMateria* Ice::clone() const
{
    Logger::printLog("Ice clone function called");
    return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
    Logger::printLog("Ice use function called");
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    Logger::printLog("Ice assignment operator called");

    if (this == &other)
        return *this;

    AMateria::operator=(other);
    return *this;
}
