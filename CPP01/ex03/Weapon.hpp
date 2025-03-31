/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/30 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
  private:
    std::string _type;

  public:
    Weapon();
    Weapon(std::string type);
    ~Weapon();
    Weapon(const Weapon& other);
    Weapon& operator=(const Weapon& other);

    std::string const& getType() const;
    void               setType(std::string type);
};

#endif
