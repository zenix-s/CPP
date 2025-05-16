#ifndef BRAIN_HPP

#define BRAIN_HPP

#include <string>

class Brain
{
  private:
    std::string ideas[100];

  public:
    Brain();
    Brain(const Brain& other);
    ~Brain();

    void printIdeas() const;
    void addIdea(const std::string& idea);

    Brain& operator=(const Brain& other);
};

#endif
