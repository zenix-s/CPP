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

        std::cout << steve->getName() << std::endl;
        std::cout << steve->getGrade() << std::endl;
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

    return EXIT_SUCCESS;
}
