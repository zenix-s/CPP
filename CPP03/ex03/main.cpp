#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    DiamondTrap diamondTrap("DiamondTrap1");
    diamondTrap.whoAmI();

    diamondTrap.Print();

    diamondTrap.attack("Target1");

    diamondTrap.takeDamage(10);

    diamondTrap.beRepaired(5);

    diamondTrap.highFivesGuys();

    diamondTrap.guardGate();

    FragTrap fragTrap("FragTrap1");
    fragTrap.Print();

    ScavTrap scavTrap("ScavTrap1");
    scavTrap.Print();
}
