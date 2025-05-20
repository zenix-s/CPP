#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

int main(void)
{
    // n your main function, create and fill an array of Animal objects. Half of it will
    // be Dog objects and the other half will be Cat objects. At the end of your program
    // execution, loop over this array and delete every Animal. You must delete directly dogs
    // and cats as Animals. The appropriate destructors must be called in the expected order.
    // Don’t forget to check for memory leaks.
    // A copy of a Dog or a Cat mustn’t be shallow. Thus, you have to test that your copies
    // are deep copies!
    //

    std::cout << Logger::getBold() << Logger::getGreen() << "First part of the test" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const AAnimal* animals[10];

        for (int i = 0; i < 5; i++)
            animals[i] = new Dog();
        for (int i = 5; i < 10; i++)
            animals[i] = new Cat();

        for (int i = 0; i < 10; i++)
            delete animals[i];
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "Add ideas to cat" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        Cat* cat = new Cat();
        cat->addIdea("I want to sleep");
        cat->addIdea("I want to eat");
        cat->addIdea("I want to play");

        cat->printIdeas();

        delete cat;
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "Add ideas to dog" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        Dog* dog = new Dog();
        std::string idea = "I want to bark";

        for (int i = 0; i < 100; i++)
            dog->addIdea(idea);

        dog->printIdeas();

        delete dog;
    }
}
