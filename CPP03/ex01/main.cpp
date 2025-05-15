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

#include "Logger.hpp"
#include "ScavTrap.hpp"
#include <iostream>

void printTrapInfo(const ScavTrap& trap)
{
    std::cout << Logger::getBlue();
    std::cout << std::endl << "------------------------------------------" << std::endl;
    std::cout << "ScavTrap info: " << std::endl;
    trap.Print();
    std::cout << "------------------------------------------" << std::endl;
    std::cout << Logger::getReset();
}

int main(void)
{
    {
        std::cout << "Creating ScavTrap instance with name 'ScavTrap1'" << std::endl;
        ScavTrap scavtrap1("ScavTrap1");

        printTrapInfo(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue();
        std::cout << "ScavTrap should attack: " << Logger::getYellow() << scavtrap1.getName() << Logger::getBlue() << std::endl;
        std::cout << "Attacking target 'Target1'" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << Logger::getReset();
        scavtrap1.attack("Target1");
        printTrapInfo(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue() << "ScavTrap take damage of 10 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap1.takeDamage(10);
        printTrapInfo(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << "ScavTrap repairing 5 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap1.beRepaired(5);
        printTrapInfo(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << "ScavTrap entering Gate Keeper mode" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap1.guardGate();
        printTrapInfo(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue() << "ScavTrap Taking damage of 100 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap1.takeDamage(100);
        printTrapInfo(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ScavTrap tries to repair 5 points, but it is dead" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap1.beRepaired(5);
        printTrapInfo(scavtrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue() << "ScavTrap tries to enter Gate Keeper mode, but it is dead" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap1.guardGate();
        printTrapInfo(scavtrap1);
        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
    }

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    {
        std::cout << "Creating ScavTrap instance with name 'ScavTrap2'" << std::endl;
        ScavTrap scavtrap2("ScavTrap2");

        printTrapInfo(scavtrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ScavTrap should attack: " << Logger::getYellow() << scavtrap2.getName() << Logger::getBlue() << " until it runs out of energy" << std::endl;

        while (scavtrap2.hasEnergy() > 0)
            scavtrap2.attack("Target2");

        printTrapInfo(scavtrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ScavTrap tries to attack, but it is out of energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap2.attack("Target2");
        printTrapInfo(scavtrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ScavTrap tries to repair 5 points, but it is out of energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap2.beRepaired(5);
        printTrapInfo(scavtrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ScavTrap enters Gate Keeper mode, since it is not dead and it does not consume energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        scavtrap2.guardGate();
    }
}
