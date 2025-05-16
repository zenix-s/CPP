#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
  private:
    std::string _type;

  public:
    Cat();
    Cat(const Cat& other);

    ~Cat();

    std::string getType() const;

    void makeSound() const;

    Cat& operator=(const Cat& before);
};

#endif
