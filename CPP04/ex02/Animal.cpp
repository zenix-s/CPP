#include "Animal.hpp"
#include "Logger.hpp"
#include <string>

AAnimal::AAnimal() : _type("Unknown creature")
{
    Logger::printLog("Animal constructor called");
}

AAnimal::AAnimal(const std::string& type) : _type(type)
{
    Logger::printLog("Animal constructor called");
}

AAnimal::AAnimal(const AAnimal& other)
{
    Logger::printLog("Animal copy constructor called");
    *this = other;
}

AAnimal::~AAnimal()
{
    Logger::printLog("Animal destructor called");
}

std::string AAnimal::getType() const
{
    return _type;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    Logger::printLog("Animal assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}
