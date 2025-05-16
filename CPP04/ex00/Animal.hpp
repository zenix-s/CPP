#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  private:
    std::string _type;

  public:
    Animal(void);
    Animal(const Animal& other);

    virtual ~Animal();

    virtual std::string getType(void) const;

    virtual void makeSound(void) const;

    Animal& operator=(const Animal& before);
};

#endif
