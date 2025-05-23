#ifndef WRONG_ANIMAL_HPP

#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
  protected:
    std::string _type;
    
    WrongAnimal(const std::string& type);
    
    void copy(const WrongAnimal& other);

  public:
    WrongAnimal(void);
    WrongAnimal(const WrongAnimal& other);

    virtual ~WrongAnimal();

    virtual std::string getType(void) const;

    void makeSound(void) const;

    WrongAnimal& operator=(const WrongAnimal& before);
};

#endif
