/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/11 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "Creating ClapTrap instance with name 'ClapTrap1'" << std::endl;
        ClapTrap claptrap1("ClapTrap1");
        std::cout << "ClapTrap instance created" << std::endl;

        std::cout << "Attacking target 'Target1'" << std::endl;
        claptrap1.attack("Target1");
        std::cout << "Attack completed" << std::endl;

        std::cout << "Taking damage of 5 points" << std::endl;
        claptrap1.takeDamage(5);
        std::cout << "Damage taken" << std::endl;

        std::cout << "Repairing 3 points" << std::endl;
        claptrap1.beRepaired(3);
        std::cout << "Repair completed" << std::endl;

        std::cout << "ClapTrap instance going out of scope" << std::endl;
    }
    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
    {
        std::cout << "Creating ClapTrap instance with name 'ClapTrap2'" << std::endl;
        ClapTrap claptrap2("ClapTrap2");
        std::cout << "ClapTrap instance created" << std::endl;

        std::cout << "Attacking target 'Target2'" << std::endl;
        claptrap2.attack("Target2");
        std::cout << "Attack completed" << std::endl;

        std::cout << "Taking damage of 10 points" << std::endl;
        claptrap2.takeDamage(10);
        std::cout << "Damage taken" << std::endl;

        std::cout << "Repairing 5 points" << std::endl;
        claptrap2.beRepaired(5);
        std::cout << "Repair completed" << std::endl;

        std::cout << "ClapTrap instance going out of scope" << std::endl;
    }
}
