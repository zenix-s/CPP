#include "ScavTrap.hpp"
#include "Logger.hpp"
#include <iostream>

const int ScavTrap::baseAttackDamage = 20;
const int ScavTrap::baseHitPoints = 100;
const int ScavTrap::baseEnergyPoints = 50;

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, baseHitPoints, baseEnergyPoints, baseAttackDamage)
{
    Logger::printLog("ScavTrap Constructor called for " + _name);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    Logger::printLog("ScavTrap Copy constructor called for " + other._name);
}

ScavTrap::~ScavTrap()
{
    Logger::printLog("ScavTrap Destructor called for " + _name);
}

void ScavTrap::attack(const std::string& target)
{
    Logger::printLog("ScavTrap attack called for " + _name);
    if (!isAlive())
    {
        std::cout << "ScavTrap " << _name << " is dead and cannot attack!" << std::endl;
        return;
    }

    if (!hasEnergy())
    {
        std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate() const
{
    Logger::printLog("ScavTrap Guard Gate function called for " + _name);

    if (!isAlive())
    {
        std::cout << "ScavTrap " << _name << " is dead and cannot enter Gate Keeper mode!" << std::endl;
        return;
    }

    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    Logger::printLog("ScavTrap Copy assignment operator called for " + _name);
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}
