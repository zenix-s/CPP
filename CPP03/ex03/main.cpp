#include "DiamondTrap.hpp"
#include "Logger.hpp"
#include <iostream>

int main(void)
{
    DiamondTrap diamondTrap("DiamondTrap1");
    diamondTrap.whoAmI();
    diamondTrap.Print();

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    std::cout << Logger::getBlue() << "DiamondTrap should attack: " << Logger::getYellow() << diamondTrap.getName() << Logger::getBlue() << std::endl;
    std::cout << "Attacking target 'Target1'" << std::endl;
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
    diamondTrap.attack("Target1");
    diamondTrap.Print();

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    std::cout << Logger::getBlue() << "DiamondTrap take damage of 10 points" << std::endl;
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
    diamondTrap.takeDamage(10);
    diamondTrap.Print();

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    std::cout << "DiamondTrap repairing 5 points" << std::endl;
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
    diamondTrap.beRepaired(5);
    diamondTrap.Print();

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    std::cout << "DiamondTrap entering Gate Keeper mode" << std::endl;
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
    diamondTrap.guardGate();

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    std::cout << Logger::getBlue() << "DiamondTrap should do high fives" << std::endl;
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
    diamondTrap.highFivesGuys();

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    std::cout << Logger::getBlue() << "DiamondTrap consumes all energy" << std::endl;
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
    while (diamondTrap.hasEnergy())
        diamondTrap.attack("Target1");
    diamondTrap.Print();

    std::cout << Logger::getBlue() << "DiamondTrap tries to attack" << std::endl << Logger::getReset();
    diamondTrap.attack("Target1");
    std::cout << Logger::getBlue() << "DiamondTrap tries to repair" << std::endl << Logger::getReset();
    diamondTrap.beRepaired(5);
    std::cout << Logger::getBlue() << "DiamondTrap tries to do high fives" << std::endl << Logger::getReset();
    diamondTrap.highFivesGuys();
    std::cout << Logger::getBlue() << "DiamondTrap tries to enter Gate Keeper mode" << std::endl << Logger::getReset();
    diamondTrap.guardGate();

    std::cout << std::endl << "------------------------------------------" << std::endl << std::endl;

    std::cout << Logger::getBlue() << "DiamondTrap should take damage of 100 points" << std::endl;
    std::cout << "------------------------------------------" << std::endl << Logger::getReset();
    diamondTrap.takeDamage(100);
    diamondTrap.Print();

    std::cout << Logger::getBlue() << "DiamondTrap tries to attack" << std::endl << Logger::getReset();
    diamondTrap.attack("Target1");
    std::cout << Logger::getBlue() << "DiamondTrap tries to repair" << std::endl << Logger::getReset();
    diamondTrap.beRepaired(5);
    std::cout << Logger::getBlue() << "DiamondTrap tries to do high fives" << std::endl << Logger::getReset();
    diamondTrap.highFivesGuys();
    std::cout << Logger::getBlue() << "DiamondTrap tries to enter Gate Keeper mode" << std::endl << Logger::getReset();
    diamondTrap.guardGate();
}
