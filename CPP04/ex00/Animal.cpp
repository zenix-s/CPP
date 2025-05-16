#include "Animal.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Animal::Animal()
{
    Logger::printLog("Animal default constructor called");
    _type = "Unknown creature";
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

void Animal::makeSound() const
{
    std::cout << "Unknown sound!" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    Logger::printLog("Animal assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}
