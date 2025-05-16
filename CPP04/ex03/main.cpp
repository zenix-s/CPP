
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Logger.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include <string>

int main(void)
{
    {
        Character* character = new Character("Player");
        AMateria*  ice = new Ice();
        AMateria*  cure = new Cure();

        character->equip(ice);
        character->equip(cure);

        Character* target = new Character("Target");

        character->use(0, *target);
        character->use(1, *target);

        delete target;
        delete character;
    }

    std::cout << std::endl << std::endl;

    {
        std::cout << Logger::getBold() << Logger::getGreen() << "Test excess of materia" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        Character* character = new Character("Player");
        AMateria*  ice = new Ice();
        AMateria*  cure = new Cure();
        AMateria*  extra = new Ice();
        AMateria*  extra2 = new Cure();
        AMateria*  extra3 = new Ice();

        character->equip(ice);
        character->equip(cure);
        character->equip(extra);
        character->equip(extra2);

        Logger::printComment("Trying to equip a fifth materia should fail");
        character->equip(extra3);

        Character* target = new Character("Target");

        Logger::printComment("Trying to use a fifth materia should fail");
        character->use(5, *target);

        delete target;
        delete character;
        Logger::printComment("Deleting extra materia");
        delete extra3;
    }

    std::cout << std::endl << std::endl;

    {
        std::cout << Logger::getBold() << Logger::getGreen() << "Test MateriaSource" << Logger::getBoldOff() << Logger::getReset() << std::endl;

        IMateriaSource* src = new MateriaSource();

        Logger::printComment("Learning materia");
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        Logger::printComment("Creating character");
        ICharacter* me = new Character("me");

        Logger::printComment("Creating and equip materia");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        Logger::printComment("Creating target");
        ICharacter* bob = new Character("bob");

        Logger::printComment("Using materia");
        me->use(0, *bob);
        me->use(1, *bob);

        Logger::printComment("Deleting objects");
        delete bob;
        delete me;
        delete src;
    }
    return 0;
}
