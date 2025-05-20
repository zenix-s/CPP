
#include "Dog.hpp"
#include "Animal.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal("Dog")
{
    Logger::printLog("Dog constructor called");
}

Dog::Dog(const Dog& other) : Animal(other)
{
    Logger::printLog("Dog copy constructor called");
    *this = other;
}

Dog::~Dog()
{
    Logger::printLog("Dog destructor called");
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
