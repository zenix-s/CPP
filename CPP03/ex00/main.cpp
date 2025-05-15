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
#include "Logger.hpp"
#include <iostream>

static void printTrapInfo(const ClapTrap& trap)
{
    std::cout << Logger::getBlue() << std::endl << "------------------------------------------" << std::endl;
    std::cout << "ScavTrap info: " << std::endl;
    trap.Print();
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
}

int main(void)
{
    {
        std::cout << Logger::getGreen() << Logger::getBold() << "Test ClapTrap, check normal actions" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        ClapTrap claptrap1("ClapTrap1");

        claptrap1.attack("Target1");
        printTrapInfo(claptrap1);
        claptrap1.takeDamage(5);
        printTrapInfo(claptrap1);
        claptrap1.beRepaired(3);
        printTrapInfo(claptrap1);
    }
    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
    {
        std::cout << Logger::getGreen() << Logger::getBold() << "Test ClapTrap, check actions when dead" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        ClapTrap claptrap("ClapTrap2");
        while (claptrap.isAlive())
            claptrap.takeDamage(10);

        printTrapInfo(claptrap);
        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ClapTrap tries to attack, but it is dead" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        claptrap.attack("Target2");
        printTrapInfo(claptrap);
        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ClapTrap tries to repair 5 points, but it is dead" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        claptrap.beRepaired(5);
        printTrapInfo(claptrap);
    }
    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
    {
        std::cout << Logger::getGreen() << Logger::getBold() << "Test ClapTrap, check actions when out of energy" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        ClapTrap claptrap("ClapTrap3");

        while (claptrap.hasEnergy())
            claptrap.attack("Target3");

        printTrapInfo(claptrap);
        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ClapTrap tries to attack, but it is out of energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        claptrap.attack("Target4");
        printTrapInfo(claptrap);
        std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;
        std::cout << Logger::getBlue() << "ClapTrap tries to repair 5 points, but it is out of energy" << std::endl;
        std::cout << "------------------------------------------" << std::endl << Logger::getReset();
        claptrap.beRepaired(5);
        printTrapInfo(claptrap);
    }
}
