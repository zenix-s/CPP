
#include "Dog.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Dog::Dog()
{
    Logger::printLog("Dog default constructor called");
    _type = "Dog";
}

Dog::Dog(const Dog& other)
{
    Logger::printLog("Dog copy constructor called");
    *this = other;
}

Dog::~Dog()
{
    Logger::printLog("Dog destructor called");
}

std::string Dog::getType() const
{
    return _type;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    Logger::printLog("Dog assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}
