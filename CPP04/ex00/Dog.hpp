#ifndef DOG_HPP

#define DOG_HPP

#include "Animal.hpp"
#include <string>

class Dog : public AAnimal
{
  private:
    std::string _type;

  public:
    Dog();
    Dog(const Dog& other);

    ~Dog();

    std::string getType() const;

    void makeSound() const;

    Dog& operator=(const Dog& before);
};

#endif
