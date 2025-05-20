#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal
{
  private:
    std::string _type;
    Brain*      _brain;

  public:
    Cat();
    Cat(const Cat& other);

    ~Cat();

    std::string getType() const;

    void makeSound() const;
    void addIdea(std::string idea);
    void printIdeas(void) const;

    Cat& operator=(const Cat& before);
};

#endif
