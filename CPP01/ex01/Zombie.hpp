/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <string>

class Zombie
{
  private:
    std::string _name;

  public:
    Zombie();
    Zombie(Zombie const& zombie);
    Zombie(std::string name);
    ~Zombie();
    Zombie& operator=(Zombie const& zombie);
    void    announce();

    void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
