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
        const Animal* animals[10];

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
        Dog*        dog = new Dog();
        std::string idea = "I want to bark";

        for (int i = 0; i < 100; i++)
            dog->addIdea(idea);

        dog->printIdeas();

        delete dog;
    }

    std::cout << std::endl << std::endl;

    Logger::printTitle("Testing deep copy of Cat");
    {
        Cat* cat = new Cat();
        cat->addIdea("I want to sleep");
        cat->addIdea("I want to eat");
        cat->addIdea("I want to play");

        Logger::printComment("Cat ideas");
        cat->printIdeas();

        Logger::printComment("Copying cat");
        Cat* copy = new Cat(*cat);

        Logger::printComment("Add idea to copy");
        copy->addIdea("COPY: I want to play with a mouse");

        Logger::printComment("Copy ideas");
        copy->printIdeas();

        Logger::printComment("Add idea to original");
        cat->addIdea("ORIGINAL: I want to play with a dog");

        Logger::printComment("Original ideas");
        cat->printIdeas();

        delete cat;
        delete copy;
    }
    
    Logger::printTitle("Testing deep copy of Dog");
    {
        Dog* dog = new Dog();
        dog->addIdea("I want to bark");
        dog->addIdea("I want to eat");
        dog->addIdea("I want to play");

        Logger::printComment("Dog ideas");
        dog->printIdeas();

        Logger::printComment("Copying dog");
        Dog* copy = new Dog(*dog);

        Logger::printComment("Add idea to copy");
        copy->addIdea("COPY: I want to play with a ball");

        Logger::printComment("Copy ideas");
        copy->printIdeas();

        Logger::printComment("Add idea to original");
        dog->addIdea("ORIGINAL: I want to play with a cat");

        Logger::printComment("Original ideas");
        dog->printIdeas();

        delete dog;
        delete copy;
    }
    
    Logger::printTitle("Testing deep copy of Brain");
    {
        Brain* brain = new Brain();
        brain->addIdea("I want to sleep");
        brain->addIdea("I want to eat");
        brain->addIdea("I want to play");

        Logger::printComment("Brain ideas");
        brain->printIdeas();

        Logger::printComment("Copying brain");
        Brain* copy = new Brain(*brain);

        Logger::printComment("Add idea to copy");
        copy->addIdea("COPY: I want to play with a mouse");

        Logger::printComment("Copy ideas");
        copy->printIdeas();

        Logger::printComment("Add idea to original");
        brain->addIdea("ORIGINAL: I want to play with a dog");

        Logger::printComment("Original ideas");
        brain->printIdeas();

        delete brain;
        delete copy;
    }
}
