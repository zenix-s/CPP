#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap
{
  public:
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);

    ~DiamondTrap();

    void whoAmI() const;

    DiamondTrap& operator=(const DiamondTrap& other);

  private:
    std::string _name;
};

#endif
