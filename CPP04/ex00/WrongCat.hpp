#ifndef WRONG_CAT_HPP

#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
  private:
    std::string _type;

  public:
    WrongCat();
    WrongCat(const WrongCat& other);

    ~WrongCat();

    std::string getType() const;

    void makeSound() const;

    WrongCat& operator=(const WrongCat& before);
};

#endif
