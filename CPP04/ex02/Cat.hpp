#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
  private:
    Brain*      _brain;

  public:
    Cat();
    Cat(const Cat& other);

    ~Cat();

    void makeSound() const;
    void addIdea(std::string idea);
    void printIdeas(void) const;

    Cat& operator=(const Cat& before);
};

#endif
