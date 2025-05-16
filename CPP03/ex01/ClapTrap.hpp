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
  protected:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;

  public:
    ClapTrap(const std::string& name);
    ClapTrap(const std::string& name, int hitPoints, int energyPoints, int attackDamage);
    ClapTrap(const ClapTrap& other);

    ~ClapTrap();

    std::string getName() const;
    bool        isAlive() const;
    bool        hasEnergy() const;

    virtual void attack(const std::string& target);
    void         takeDamage(unsigned int amount);
    void         beRepaired(unsigned int amount);

    ClapTrap& operator=(const ClapTrap& other);

    void Print() const;
};

#endif
