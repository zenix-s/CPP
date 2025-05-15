/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/11 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "Logger.hpp"
#include <iostream>

bool ClapTrap::isAlive() const
{
    Logger::printLog("ClapTrap isAlive function called for " + _name);
    return _hitPoints > 0;
}

bool ClapTrap::hasEnergy() const
{
    Logger::printLog("ClapTrap hasEnergy function called for " + _name);
    return _energyPoints > 0;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    Logger::printLog("ClapTrap Constructor called for " + _name);
}

ClapTrap::ClapTrap(const std::string& name, const int hitPoints, const int energyPoints, const int attackDamage)
    : _name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
    Logger::printLog("ClapTrap Constructor called for " + _name + " with parameters");
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    Logger::printLog("ClapTrap Copy constructor called for " + other._name);
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap::~ClapTrap()
{
    Logger::printLog("ClapTrap Destructor called for " + _name);
}

std::string ClapTrap::getName() const
{
    Logger::printLog("ClapTrap getName function called for " + _name);
    return _name;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    Logger::printLog("ClapTrap Copy assignment operator called for " + _name);

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
    Logger::printLog("ClapTrap attack function called for " + _name);
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
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    Logger::printLog("ClapTrap takeDamage function called for " + _name);
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
    Logger::printLog("ClapTrap beRepaired function called for " + _name);
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
