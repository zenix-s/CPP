#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>
class ClapTrap
{
  private:
    std::string _name;
    int         _hitPoints;
    int         _energyPoints;
    int         _attackDamage;
    
    bool isAlive() const;
    bool hasEnergy() const;

  public:
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ~ClapTrap();

    ClapTrap& operator=(const ClapTrap& other);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
