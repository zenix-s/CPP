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

#include "FragTrap.hpp"
#include "Logger.hpp"
#include <iostream>

void printTrapInfo(const FragTrap& trap)
{
    std::cout << Logger::getBlue();
    std::cout << std::endl << "------------------------------------------" << std::endl;
    std::cout << "FragTrap info: " << std::endl;
    trap.Print();
    std::cout << "------------------------------------------" << std::endl;
    std::cout << Logger::getReset();
}

int main(void)
{
    {
        std::cout << "Creating FragTrap instance with name 'FragTrap1'" << std::endl;
        FragTrap FragTrap1("FragTrap1");

        printTrapInfo(FragTrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue();
        std::cout << "FragTrap should attack: " << Logger::getYellow() << FragTrap1.getName() << Logger::getBlue() << std::endl;
        std::cout << "Attacking target 'Target1'" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << Logger::getReset();
        FragTrap1.attack("Target1");
        printTrapInfo(FragTrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue() << "FragTrap take damage of 10 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap1.takeDamage(10);
        printTrapInfo(FragTrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << "FragTrap repairing 5 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap1.beRepaired(5);
        printTrapInfo(FragTrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << "FragTrap entering Gate Keeper mode" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap1.highFivesGuys();
        printTrapInfo(FragTrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue() << "FragTrap Taking damage of 100 points" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap1.takeDamage(100);
        printTrapInfo(FragTrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "FragTrap tries to repair 5 points, but it is dead" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap1.beRepaired(5);
        printTrapInfo(FragTrap1);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

        std::cout << Logger::getBlue() << "FragTrap tries to do high fives, but it is dead" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap1.highFivesGuys();
        printTrapInfo(FragTrap1);
        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
    }

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    {
        std::cout << "Creating FragTrap instance with name 'FragTrap2'" << std::endl;
        FragTrap FragTrap2("FragTrap2");

        printTrapInfo(FragTrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "FragTrap should attack: " << Logger::getYellow() << FragTrap2.getName() << Logger::getBlue() << " until it runs out of energy" << std::endl;

        while (FragTrap2.hasEnergy() > 0)
            FragTrap2.attack("Target2");

        printTrapInfo(FragTrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "FragTrap tries to attack, but it is out of energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap2.attack("Target2");
        printTrapInfo(FragTrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "FragTrap tries to repair 5 points, but it is out of energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap2.beRepaired(5);
        printTrapInfo(FragTrap2);

        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "FragTrap tries to give high fives, but it is out of energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        FragTrap2.highFivesGuys();
    }
}
