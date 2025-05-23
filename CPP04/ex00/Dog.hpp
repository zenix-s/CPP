#ifndef DOG_HPP

#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
  private:
    void copy(const Dog& other);

  public:
    Dog();
    Dog(const Dog& other);

    ~Dog();

    void makeSound() const;

    Dog& operator=(const Dog& before);
};

#endif
