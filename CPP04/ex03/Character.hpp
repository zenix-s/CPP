#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter
{
  private:
    std::string _name;
    AMateria*   _materia[4];

  public:
    Character(std::string const& name);
    Character(Character const& other);

    ~Character();

    const std::string& getName() const;
    void               equip(AMateria* m);
    void               unequip(int idx);
    void               use(int idx, ICharacter& target);

    Character& operator=(Character const& other);
};

#endif
