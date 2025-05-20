#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Logger.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
    Logger::printLog("Default main");
    {
        const AAnimal* animal = new AAnimal();
        const AAnimal* dog = new Dog();
        const AAnimal* cat = new Cat();

        Logger::printComment("Printing dog and cat types");

        std::cout << dog->getType() << " " << std::endl;
        std::cout << cat->getType() << " " << std::endl;

        Logger::printComment("Printing animal types of dog and cat");
        std::cout << dog->AAnimal::getType() << " " << std::endl;
        std::cout << cat->AAnimal::getType() << " " << std::endl;

        Logger::printComment("Making sounds");
        cat->makeSound(); // will output the cat sound!
        dog->makeSound();
        animal->makeSound();

        Logger::printComment("Deleting objects");
        delete animal;
        delete dog;
        delete cat;
    }

    std::cout << std::endl << std::endl;

    Logger::printComment("Constructors and destructors of each class must display specific messages");

    Logger::printTitle("Testing Animal");
    {
        const AAnimal* animal = new AAnimal();
        delete animal;
    }

    Logger::printTitle("Testing Dog");
    {
        const AAnimal* dog = new Dog();
        delete dog;
    }

    Logger::printTitle("Testing Cat");
    {
        const AAnimal* cat = new Cat();
        delete cat;
    }

    Logger::printTitle("Testing WrongAnimal");
    {
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        delete wrongAnimal;
    }

    Logger::printTitle("Testing WrongCat");
    {
        const WrongAnimal* wrongCat = new WrongCat();
        delete wrongCat;
    }

    std::cout << std::endl << std::endl;

    Logger::printTitle("Testing copy constructor");

    Logger::printTitle("Testing animal");
    {
        const AAnimal* animal = new AAnimal();
        const AAnimal* copy = new AAnimal(*animal);

        Logger::printComment("Since type is protected, the only way to access it is through a getter");
        std::cout << copy->getType() << std::endl;

        delete animal;
        delete copy;
    }

    Logger::printTitle("Testing dog");
    {
        const Dog* dog = new Dog();
        const Dog* copy = new Dog(*dog);

        Logger::printComment("Dog type should be dog");
        std::cout << copy->getType() << std::endl;

        Logger::printComment("Animal type of dog is different");
        std::cout << copy->AAnimal::getType() << std::endl;

        Logger::printComment("Dog should bark");
        copy->makeSound();

        delete dog;
        delete copy;
    }

    Logger::printTitle("Testing cat");
    {
        const Cat* cat = new Cat();
        const Cat* copy = new Cat(*cat);

        Logger::printComment("Cat type should be cat");
        std::cout << copy->getType() << std::endl;

        Logger::printComment("Animal type of cat is different");
        std::cout << copy->AAnimal::getType() << std::endl;

        Logger::printComment("Cat should meow");
        copy->makeSound();

        delete cat;
        delete copy;
    }

    Logger::printTitle("Testing wrong animal");
    {
        const WrongAnimal* wrongAnimal = new WrongAnimal();
        const WrongAnimal* copy = new WrongAnimal(*wrongAnimal);

        Logger::printComment("Since type is protected, the only way to access it is through a getter");
        std::cout << copy->getType() << std::endl;

        delete wrongAnimal;
        delete copy;
    }

    Logger::printTitle("Testing wrong cat");
    {
        const WrongCat* wrongCat = new WrongCat();
        const WrongCat* copy = new WrongCat(*wrongCat);

        Logger::printComment("WrongCat type should be WrongCat");
        std::cout << copy->getType() << std::endl;

        Logger::printComment("WrongCat should not meow");
        copy->makeSound();

        delete wrongCat;
        delete copy;
    }

    std::cout << std::endl << std::endl;

    Logger::printTitle("Testing Animal");
    {
        AAnimal* animal = new AAnimal();

        Logger::printComment("Since type is protected, the only way to access it is through a getter");
        std::cout << animal->getType() << std::endl;

        delete animal;
    }

    std::cout << std::endl << std::endl;

    Logger::printTitle("Testing Dog");
    {
        Dog* dog = new Dog();

        Logger::printComment("Dog type should be dog");
        std::cout << dog->getType() << std::endl;

        Logger::printComment("Animal type of dog is different");
        std::cout << dog->AAnimal::getType() << std::endl;

        Logger::printComment("Dog should bark");
        dog->makeSound();

        delete dog;
    }

    std::cout << std::endl << std::endl;

    Logger::printTitle("Testing Cat");
    {
        Cat* cat = new Cat();

        Logger::printComment("Cat type should be cat");
        std::cout << cat->getType() << std::endl;

        Logger::printComment("Animal type of cat is different");
        std::cout << cat->AAnimal::getType() << std::endl;

        Logger::printComment("Cat should meow");
        cat->makeSound();

        delete cat;
    }

    std::cout << std::endl << std::endl;

    Logger::printTitle("Testing WrongAnimal");
    {
        WrongAnimal* wrongAnimal = new WrongAnimal();

        Logger::printComment("Since type is protected, the only way to access it is through a getter");
        std::cout << wrongAnimal->getType() << std::endl;

        delete wrongAnimal;
    }

    std::cout << std::endl << std::endl;

    Logger::printTitle("Testing WrongCat");
    {
        WrongCat* wrongCat = new WrongCat();

        Logger::printComment("WrongCat type should be WrongCat");
        std::cout << wrongCat->getType() << std::endl;

        Logger::printComment("WrongCat should not meow");
        wrongCat->makeSound();

        delete wrongCat;
    }
}
