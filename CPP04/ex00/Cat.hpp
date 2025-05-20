#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
  public:
    Cat();
    Cat(const Cat& other);

    ~Cat();

    void makeSound() const;

    Cat& operator=(const Cat& before);
};

#endif
