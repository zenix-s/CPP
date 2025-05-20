#include "Animal.hpp"
#include "Logger.hpp"
#include <string>

Animal::Animal() : _type("Unknown creature")
{
    Logger::printLog("Animal constructor called");
}

Animal::Animal(const std::string& type) : _type(type)
{
    Logger::printLog("Animal constructor called");
}

Animal::Animal(const Animal& other)
{
    Logger::printLog("Animal copy constructor called");
    *this = other;
}

Animal::~Animal()
{
    Logger::printLog("Animal destructor called");
}

std::string Animal::getType() const
{
    return _type;
}

Animal& Animal::operator=(const Animal& other)
{
    Logger::printLog("Animal assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}
