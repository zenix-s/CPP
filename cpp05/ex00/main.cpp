#include <cstdlib>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Logger.hpp"

int main(void)
{
    Logger::printTitle("Default constructor");
    {
        Bureaucrat* steve = new Bureaucrat();

        std::cout << *steve << std::endl;
        delete steve;
    }

    Logger::printLineJunp();
    Logger::printTitle("Name constructor");
    {
        Bureaucrat* juan = new Bureaucrat("Juan");

        std::cout << juan->getName() << std::endl;
        std::cout << juan->getGrade() << std::endl;
        delete juan;
    }

    Logger::printLineJunp();
    Logger::printTitle("Full constructor");
    {
        Bureaucrat* santiago = new Bureaucrat("Santiago", 1);

        std::cout << santiago->getName() << std::endl;
        std::cout << santiago->getGrade() << std::endl;
        delete santiago;
    }

    Logger::printLineJunp();
    Logger::printTitle("Full constructor grade above 1");
    {
        try
        {
            Bureaucrat* santiago = new Bureaucrat("Santiago", 0);

            std::cout << santiago->getName() << std::endl;
            std::cout << santiago->getGrade() << std::endl;
            delete santiago;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooHighException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Full constructor grade below 150");
    {
        try
        {
            Bureaucrat* santiago = new Bureaucrat("Santiago", 151);

            std::cout << santiago->getName() << std::endl;
            std::cout << santiago->getGrade() << std::endl;
            delete santiago;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooLowException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Increment grade, works normal");
    {
        try
        {
            Bureaucrat* pablo = new Bureaucrat("Pablo", 2);

            Logger::printComment("Before:");
            std::cout << pablo->getName() << std::endl;
            std::cout << pablo->getGrade() << std::endl;

            pablo->incrementGrade();

            Logger::printComment("After:");
            std::cout << pablo->getName() << std::endl;
            std::cout << pablo->getGrade() << std::endl;

            delete pablo;
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Decrement grade, works normal");
    {
        try
        {
            Bureaucrat* pedro = new Bureaucrat("Pedro", 1);

            Logger::printComment("Before:");
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            pedro->decrementGrade();

            Logger::printComment("After:");
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            delete pedro;
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Increment grade, throws exception when out of bounds");
    {
        Bureaucrat* pedro = new Bureaucrat("Pedro", 1);
        try
        {
            Logger::printComment("Before:");
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            pedro->incrementGrade();

            delete pedro;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooHighException has ocurred");
            Logger::printError(ex.what());

            delete pedro;
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());

            delete pedro;
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Increment grade, throws exception when out of bounds");
    {
        Bureaucrat* pedro = new Bureaucrat("Pedro", 150);
        try
        {
            Logger::printComment("Before:");
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            pedro->decrementGrade();

            delete pedro;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooLowException has ocurred");
            Logger::printError(ex.what());
            delete pedro;
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
            delete pedro;
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Copy constructor");
    {
        Bureaucrat* juan = new Bureaucrat("Juan", 100);
        Bureaucrat* copy = new Bureaucrat(*juan);

        Logger::printComment("Juan:");
        std::cout << *juan << std::endl;

        Logger::printComment("Copy:");
        std::cout << *copy << std::endl;

        delete juan;
        delete copy;
    }

    Logger::printLineJunp();
    Logger::printTitle("Equal operator");
    {
        Bureaucrat* juan = new Bureaucrat("Juan", 100);
        Bureaucrat* copy = new Bureaucrat();

        Logger::printComment("Juan:");
        std::cout << *juan << std::endl;

        Logger::printComment("Copy:");
        std::cout << *copy << std::endl;

        *copy = *juan;

        Logger::printComment("After equal operator:");
        std::cout << *copy << std::endl;

        delete juan;
        delete copy;
    }

    Logger::printLineJunp();
    Logger::printTitle("Destructor");
    {
        Bureaucrat* juan = new Bureaucrat("Juan", 100);
        delete juan;
    }

    Logger::printLineJunp();
    Logger::printTitle("Destructor with exception");
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 0);
            delete juan;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooHighException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Destructor with exception");
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 151);
            delete juan;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooLowException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    return EXIT_SUCCESS;
}
