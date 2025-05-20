
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Dog::Dog() : AAnimal("100% certified good boy")
{
    Logger::printLog("Dog constructor called");
    _type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
    Logger::printLog("Dog copy constructor called");
    *this = other;
}

Dog::~Dog()
{
    delete _brain;
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

    if (this == &other)
        return *this;

    delete _brain;
    _brain = other._brain;
    _type = other._type;
    AAnimal::_type = other.AAnimal::_type;
    return *this;
}
