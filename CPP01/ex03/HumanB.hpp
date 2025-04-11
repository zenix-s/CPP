/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumabB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/11 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

class HumanB
{
  private:
    std::string _name;
    Weapon*     _weapon;

  public:
    HumanB(std::string name);
    ~HumanB();
    HumanB(const HumanB& other);
    HumanB& operator=(const HumanB& other);

    void attack();
    void setWeapon(Weapon& weapon);
};

#endif
