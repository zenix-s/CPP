#include "FragTrap.hpp"
#include "Logger.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
{
    Logger::printLog("FragTrap Constructor called for " + _name);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    Logger::printLog("FragTrap Copy constructor called for " + other._name);
}

FragTrap::~FragTrap()
{
    Logger::printLog("FragTrap Destructor called for " + _name);
}

void FragTrap::highFivesGuys() const
{
    Logger::printLog("FragTrap Guard Gate function called for " + _name);

    if (!isAlive())
    {
        std::cout << "FragTrap " << _name << " is dead and cannot do high fives!" << std::endl;
        return;
    }

    std::cout << "FragTrap " << _name << " gives a high five!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    Logger::printLog("FragTrap Copy assignment operator called for " + _name);
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}
