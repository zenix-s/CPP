/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/11 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
  public:
    static const int baseHitPoints;
    static const int baseEnergyPoints;
    static const int baseAttackDamage;

    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& other);

    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate() const;

    ScavTrap& operator=(const ScavTrap& other);
};

#endif
