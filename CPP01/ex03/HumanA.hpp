#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
  private:
    std::string _name;
    Weapon*     _weapon;

  public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    HumanA(const HumanA& other);
    HumanA& operator=(const HumanA& other);

    void attack();
    void setWeapon(Weapon& weapon);
};

#endif
