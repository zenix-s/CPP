#ifndef DOG_HPP

#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
  private:
    std::string _type;
    Brain*      _brain;

  public:
    Dog();
    Dog(const Dog& other);

    ~Dog();

    std::string getType() const;

    void makeSound() const;
    void addIdea(std::string idea);
    void printIdeas(void) const;

    Dog& operator=(const Dog& before);
};

#endif
