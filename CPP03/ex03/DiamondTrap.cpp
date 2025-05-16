#include "DiamondTrap.hpp"

#include "FragTrap.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    Logger::printLog("DiamondTrap Constructor called for " + _name);
    _hitPoints = FragTrap::baseHitPoints;
    _energyPoints = ScavTrap::baseEnergyPoints;
    _attackDamage = FragTrap::baseAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    Logger::printLog("DiamondTrap Copy constructor called for " + other._name);
}

DiamondTrap::~DiamondTrap()
{
    Logger::printLog("DiamondTrap Destructor called for " + _name);
}

void DiamondTrap::whoAmI() const
{
    Logger::printLog("DiamondTrap whoAmI function called for " + _name);
    std::cout << "DiamondTrap name: " << _name << " | " << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    Logger::printLog("DiamondTrap Copy assignment operator called for " + _name);
    if (this == &other)
        return *this;
    _name = other._name;
    ClapTrap::operator=(other);
    return *this;
}
