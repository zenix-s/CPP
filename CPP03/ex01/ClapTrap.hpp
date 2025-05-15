/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/11 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
class ClapTrap
{
  private:
  protected:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

    bool isAlive() const;
    bool hasEnergy() const;

    /**
     * Consume x amount of energy
     * @return true if energy was consumed, false in case it was alredy dead or out of energy
     */
    bool consumeEnergy(int amount);

  public:
    /**
     *
     * @param name Trap name
     */
    ClapTrap(const std::string& name);

    /**
     *
     * @param name Trap name
     * @param hitPoints Trap hit points
     * @param energyPoints Trap energy points
     * @param attackDamage Trap attack damage
     */
    ClapTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage);

    /**
     *
     * @param other ClapTrap object to copy
     */
    ClapTrap(const ClapTrap& other);

    /**
     * Destructor
     */
    ~ClapTrap();

    // Getters
    std::string getName() const;
    int         getHitPoints() const;
    int         getEnergyPoints() const;
    int         getAttackDamage() const;

    /**
     * Attack a target
     * @param target Name of the target to attack
     */
    void attack(const std::string& target);

    /**
     * Take x amount of damage
     * @param amount amount of damage to take
     */
    void takeDamage(unsigned int amount);

    /**
     * Repair x amount of damage
     * @param amount amount of energy to be repaired
     */
    void beRepaired(unsigned int amount);

    /**
     * Assignment operator
     * @param other ClapTrap object to copy
     * @return ClapTrap object
     */
    ClapTrap& operator=(const ClapTrap& other);
};

#endif
