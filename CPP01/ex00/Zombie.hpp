#ifndef ZOMBIE_HPP

#define ZOMBIE_HPP

#include <string>

class Zombie
{
  private:
    std::string _name;

  public:
    Zombie();
    Zombie(Zombie const& zombie);
    Zombie(std::string name);
    ~Zombie();
    Zombie& operator=(Zombie const& zombie);
    void    announce();
};

// This function creates a zombie, names it, and returns it so you can use it outside of the function scope.
Zombie* newZombie(std::string name);
// This function creates a zombie, names it, and makes it announce itself.
void randomChump(std::string name);

#endif
