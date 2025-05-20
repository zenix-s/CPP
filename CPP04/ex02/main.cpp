#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Logger.hpp"
#include <iostream>

int main(void)
{
    std::cout << Logger::getBold() << Logger::getGreen() << "First part of the test" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const Animal* animals[10];

        for (int i = 0; i < 5; i++)
            animals[i] = new Dog();
        for (int i = 5; i < 10; i++)
            animals[i] = new Cat();

        for (int i = 0; i < 10; i++)
        {
            std::cout << animals[i]->getType() << std::endl;
            animals[i]->makeSound();
        }

        for (int i = 0; i < 10; i++)
            delete animals[i];

        // const Animal* animal = new Animal();
    }
}
