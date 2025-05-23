#ifndef DOG_HPP

#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
  private:
    Brain* _brain;
    void   copy(const Dog& other);

  public:
    Dog();
    Dog(const Dog& other);

    ~Dog();

    void makeSound() const;
    void addIdea(std::string idea);
    void printIdeas(void) const;

    Dog& operator=(const Dog& before);
};

#endif
