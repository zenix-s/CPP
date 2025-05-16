
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Logger.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
    Logger::printLog("Cure constructor called");
}

Cure::Cure(const Cure& other) : AMateria(other)
{
    Logger::printLog("Cure copy constructor called");
    *this = other;
}

Cure::~Cure()
{
    Logger::printLog("Cure destructor called");
}

AMateria* Cure::clone() const
{
    Logger::printLog("Cure clone function called");
    return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
    Logger::printLog("Cure use function called");
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    Logger::printLog("Cure assignment operator called");

    if (this == &other)
        return *this;

    AMateria::operator=(other);
    return *this;
}
