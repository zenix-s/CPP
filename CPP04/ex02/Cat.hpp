#ifndef CAT_HPP

#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
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
    void addIdea(const std::string& idea);
    void printIdeas() const;

    Cat& operator=(const Cat& before);
};

#endif
