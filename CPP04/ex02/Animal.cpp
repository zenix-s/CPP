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
    copy(other);
}

Animal::~Animal()
{
    Logger::printLog("Animal destructor called");
}

void Animal::copy(const Animal& other)
{
    Logger::printLog("Animal copy function called");
    _type = other._type;
}

std::string Animal::getType() const
{
    return _type;
}

Animal& Animal::operator=(const Animal& other)
{
    Logger::printLog("Animal assignment operator called");

    if (this != &other)
        copy(other);

    return *this;
}
