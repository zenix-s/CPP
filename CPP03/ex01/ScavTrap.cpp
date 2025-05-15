/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FILENAME                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: CURRENT_YEAR/MONTH/DAY 18:01:21 by serferna          #+#    #+#             */
/*   Updated: YEAR/MONTH/DAY 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "Logger.hpp"
#include <iostream>
#define LOG 1

// Private member functions

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20)
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
