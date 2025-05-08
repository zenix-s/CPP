#include "ClapTrap.hpp"
#include <iostream>

// Private member functions

bool ClapTrap::isAlive() const
{
    return _hitPoints > 0;
}

bool ClapTrap::hasEnergy() const
{
    return _energyPoints > 0;
}

// Public member functions
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Constructor called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called for " << _name << std::endl;
    *this = other;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called for " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called for " << _name << std::endl;
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (!isAlive())
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }

    if (!hasEnergy())
    {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (!isAlive())
    {
        std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
        return;
    }

    _hitPoints -= amount;
    if (_hitPoints <= 0)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _name << " has taken too much damage and is now dead!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!isAlive())
    {
        std::cout << "ClapTrap " << _name << " is dead and cannot be repaired!" << std::endl;
        return;
    }

    if (!hasEnergy())
    {
        std::cout << "ClapTrap " << _name << " has no energy left to be repaired!" << std::endl;
        return;
    }

    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " has been repaired by " << amount << " points!" << std::endl;
}