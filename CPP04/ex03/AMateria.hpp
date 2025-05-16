#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
  protected:
    std::string _type;

  public:
    AMateria(std::string const& type);
    AMateria(AMateria const& other);

    virtual ~AMateria();
    // [...]
    std::string const& getType() const; // Returns the materia type
    virtual AMateria*  clone() const = 0;
    virtual void       use(ICharacter& target);

    AMateria& operator=(AMateria const& other);
};

#endif
