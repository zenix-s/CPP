#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Logger.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
    std::cout << Logger::getBold() << Logger::getGreen() << "Default main" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "Constructors and destructors of each class must display specific messages" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    std::cout << Logger::getBold() << Logger::getGreen() << "Testing Animal" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const Animal* meta = new Animal();
        delete meta;
    }

    std::cout << Logger::getBold() << Logger::getGreen() << "Testing Dog" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const Animal* meta = new Dog();
        delete meta;
    }

    std::cout << Logger::getBold() << Logger::getGreen() << "Testing Cat" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const Animal* meta = new Cat();
        delete meta;
    }

    std::cout << Logger::getBold() << Logger::getGreen() << "Testing WrongAnimal" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const WrongAnimal* meta = new WrongAnimal();
        delete meta;
    }

    std::cout << Logger::getBold() << Logger::getGreen() << "Testing WrongCat" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        const WrongAnimal* meta = new WrongCat();
        delete meta;
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "mplementing a simple base class called Animal." << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        Animal* animal = new Animal();

        std::cout << Logger::getBold() << Logger::getGreen() << "It has one protected attribute: std::string type" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        std::cout << animal->getType() << std::endl;

        delete animal;
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "mplement a Dog class that inherits from Animal" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        Dog* dog = new Dog();

        std::cout << Logger::getBold() << Logger::getGreen() << "These two derived classes must set their type field depending on their name" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        std::cout << dog->getType() << std::endl;

        std::cout << Logger::getBold() << Logger::getGreen() << "Every animal must be able to use the member function" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        std::cout << Logger::getBold() << Logger::getGreen() << "makeSound()" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        dog->makeSound(); // will output the dog sound!

        delete dog;
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "Implement a Cat class that inherits from Animal" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        Cat* cat = new Cat();

        std::cout << Logger::getBold() << Logger::getGreen() << "These two derived classes must set their type field depending on their name" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        std::cout << cat->getType() << std::endl;

        std::cout << Logger::getBold() << Logger::getGreen() << "Every animal must be able to use the member function" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        std::cout << Logger::getBold() << Logger::getGreen() << "makeSound()" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        cat->makeSound(); // will output the cat sound!

        delete cat;
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "Implement a WrongAnimal class" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        WrongAnimal* wrongAnimal = new WrongAnimal();

        std::cout << Logger::getBold() << Logger::getGreen() << "It has one protected attribute: std::string type" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        std::cout << wrongAnimal->getType() << std::endl;

        delete wrongAnimal;
    }

    std::cout << std::endl << std::endl;

    std::cout << Logger::getBold() << Logger::getGreen() << "Implement a WrongCat class that inherits from WrongAnimal" << Logger::getBoldOff() << Logger::getReset() << std::endl;
    {
        WrongCat* wrongCat = new WrongCat();

        std::cout << Logger::getBold() << Logger::getGreen() << "These two derived classes must set their type field depending on their name" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        std::cout << wrongCat->getType() << std::endl;

        std::cout << Logger::getBold() << Logger::getGreen() << "Every animal must be able to use the member function" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        std::cout << Logger::getBold() << Logger::getGreen() << "makeSound()" << Logger::getBoldOff() << Logger::getReset() << std::endl;
        wrongCat->makeSound(); // will output the cat sound!

        delete wrongCat;
    }
}
