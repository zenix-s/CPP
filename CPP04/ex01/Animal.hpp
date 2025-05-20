#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class AAnimal
{
  protected:
    std::string _type;

    AAnimal(const std::string& type);

  public:
    AAnimal(void);
    AAnimal(const AAnimal& other);

    virtual ~AAnimal();

    virtual std::string getType(void) const;

    virtual void makeSound(void) const;

    AAnimal& operator=(const AAnimal& before);
};

#endif
