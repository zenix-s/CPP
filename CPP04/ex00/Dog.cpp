
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
    copy(other);
}

Dog::~Dog()
{
    Logger::printLog("Dog destructor called");
}

void Dog::copy(const Dog& other)
{
    Logger::printLog("Dog copy function called");
    (void)other; // Prevent unused variable warning
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    Logger::printLog("Dog assignment operator called");

    if (this != &other)
        copy(other);

    return *this;
}
