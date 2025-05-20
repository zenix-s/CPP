#ifndef WRONG_ANIMAL_HPP

#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
  private:
    std::string _type;

  public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& other);

    virtual ~WrongAnimal();

    virtual std::string getType(void) const;

    void makeSound(void) const;

    WrongAnimal& operator=(const WrongAnimal& before);
};

#endif
