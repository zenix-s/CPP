
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal("Dog")
{
    Logger::printLog("Dog constructor called");
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other)
{
    Logger::printLog("Dog copy constructor called");
    copy(other);
}

Dog::~Dog()
{
    delete _brain;
    Logger::printLog("Dog destructor called");
}

void Dog::copy(const Dog& other)
{
    Logger::printLog("Dog copy function called");
    _type = other._type;
    _brain = other._brain ? new Brain(*other._brain) : NULL;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::addIdea(std::string idea)
{
    if (!_brain)
        return;
    Logger::printLog("Dog addIdea to brain called");
    _brain->addIdea(idea);
}

void Dog::printIdeas() const
{
    if (!_brain)
        return;
    Logger::printLog("Dog print ideas");
    _brain->printIdeas();
}

Dog& Dog::operator=(const Dog& other)
{
    Logger::printLog("Dog assignment operator called");

    if (this != &other)
    {
        delete _brain;
        copy(other);
    }

    return *this;
}
