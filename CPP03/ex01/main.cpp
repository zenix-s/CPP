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

#include "ScavTrap.hpp"
#include "Utils.hpp"
#include <iostream>

void printTrapInfor(const ScavTrap& trap)
{
        std::cout << Utils::getBlue();
        std::cout << std::endl << "------------------------------------------" << std::endl;
        std::cout << "ScavTrap info: " << std::endl;
        std::cout << "Name: " << Utils::getYellow() << trap.getName() << Utils::getBlue() << std::endl;
        std::cout << "Hit Points: " << Utils::getYellow() << trap.getHitPoints() << Utils::getBlue() << std::endl;
        std::cout << "Energy Points: " << Utils::getYellow() << trap.getEnergyPoints() << Utils::getBlue() << std::endl;
        std::cout << "Attack Damage: " << Utils::getYellow() << trap.getAttackDamage() << Utils::getBlue() << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << Utils::getReset();
}

int main(void)
{
    {
        std::cout << "Creating ScavTrap instance with name 'ScavTrap1'" << std::endl;
        ScavTrap scavtrap1("ScavTrap1");

        printTrapInfor(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl ;

        std::cout << Utils::getBlue();
        std::cout << "ScavTrap should attack: " << Utils::getYellow() << scavtrap1.getName() << Utils::getBlue() << std::endl;
        std::cout << "Attacking target 'Target1'" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << Utils::getReset();
        scavtrap1.attack("Target1");
        printTrapInfor(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl ;

        // std::cout << "Taking damage of 10 points" << std::endl;
        // scavtrap1.takeDamage(10);
        //
        // std::cout << "Damage taken" << std::endl;
        // std::cout << "Repairing 5 points" << std::endl;
        // scavtrap1.beRepaired(5);
        //
        // std::cout << "Repair completed" << std::endl;
        // std::cout << "Entering Gate Keeper mode" << std::endl;
        // scavtrap1.guardGate();


        std::cout << Utils::getBlue();
        std::cout << "Scav trap take damage of 10 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << Utils::getReset();
        scavtrap1.takeDamage(10);
        printTrapInfor(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl ;

        std::cout << Utils::getBlue() << "ScavTrap take damage of 10 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Utils::getReset();


    }
    // std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
    // {
    //     std::cout << "Creating ClapTrap instance with name 'ClapTrap2'" << std::endl;
    //     ClapTrap claptrap2("ClapTrap2");
    //     std::cout << "ClapTrap instance created" << std::endl;
    //
    //     std::cout << "Attacking target 'Target2'" << std::endl;
    //     claptrap2.attack("Target2");
    //     std::cout << "Attack completed" << std::endl;
    //
    //     std::cout << "Taking damage of 10 points" << std::endl;
    //     claptrap2.takeDamage(10);
    //     std::cout << "Damage taken" << std::endl;
    //
    //     std::cout << "Repairing 5 points" << std::endl;
    //     claptrap2.beRepaired(5);
    //     std::cout << "Repair completed" << std::endl;
    //
    //     std::cout << "ClapTrap instance going out of scope" << std::endl;
    // }
}
