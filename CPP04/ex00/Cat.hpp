#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
  private:
    void copy(const Cat& other);

  public:
    Cat();
    Cat(const Cat& other);

    ~Cat();

    void makeSound() const;

    Cat& operator=(const Cat& before);
};

#endif
