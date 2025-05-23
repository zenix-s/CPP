#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
  protected:
    std::string _type;
    Animal(const std::string& type);
    void copy(const Animal& other);

  public:
    Animal(void);
    Animal(const Animal& other);

    virtual ~Animal();

    virtual std::string getType(void) const;

    virtual void makeSound(void) const;

    Animal& operator=(const Animal& other);
};

#endif
