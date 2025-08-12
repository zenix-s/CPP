#include <cstdlib>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "=== Default constructor ===" << std::endl;
    {
        Bureaucrat* steve = new Bureaucrat();

        std::cout << *steve << std::endl;
        delete steve;
    }

    std::cout << std::endl;
    std::cout << "=== Name constructor ===" << std::endl;
    {
        Bureaucrat* juan = new Bureaucrat("Juan");

        std::cout << juan->getName() << std::endl;
        std::cout << juan->getGrade() << std::endl;
        delete juan;
    }

    std::cout << std::endl;
    std::cout << "=== Full constructor ===" << std::endl;
    {
        Bureaucrat* santiago = new Bureaucrat("Santiago", 1);

        std::cout << santiago->getName() << std::endl;
        std::cout << santiago->getGrade() << std::endl;
        delete santiago;
    }

    std::cout << std::endl;
    std::cout << "=== Full constructor grade above 1 ===" << std::endl;
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
            std::cout << "Exception Bureaucrat::GradeTooHighException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Full constructor grade below 150 ===" << std::endl;
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
            std::cout << "Exception Bureaucrat::GradeTooLowException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Increment grade, works normal ===" << std::endl;
    {
        try
        {
            Bureaucrat* pablo = new Bureaucrat("Pablo", 2);

            std::cout << "Before:" << std::endl;
            std::cout << pablo->getName() << std::endl;
            std::cout << pablo->getGrade() << std::endl;

            pablo->incrementGrade();

            std::cout << "After:" << std::endl;
            std::cout << pablo->getName() << std::endl;
            std::cout << pablo->getGrade() << std::endl;

            delete pablo;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Decrement grade, works normal ===" << std::endl;
    {
        try
        {
            Bureaucrat* pedro = new Bureaucrat("Pedro", 1);

            std::cout << "Before:" << std::endl;
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            pedro->decrementGrade();

            std::cout << "After:" << std::endl;
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            delete pedro;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Increment grade, throws exception when out of bounds ===" << std::endl;
    {
        Bureaucrat* pedro = new Bureaucrat("Pedro", 1);
        try
        {
            std::cout << "Before:" << std::endl;
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            pedro->incrementGrade();

            delete pedro;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            std::cout << "Exception Bureaucrat::GradeTooHighException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;

            delete pedro;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;

            delete pedro;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Decrement grade, throws exception when out of bounds ===" << std::endl;
    {
        Bureaucrat* pedro = new Bureaucrat("Pedro", 150);
        try
        {
            std::cout << "Before:" << std::endl;
            std::cout << pedro->getName() << std::endl;
            std::cout << pedro->getGrade() << std::endl;

            pedro->decrementGrade();

            delete pedro;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            std::cout << "Exception Bureaucrat::GradeTooLowException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
            delete pedro;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
            delete pedro;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Copy constructor ===" << std::endl;
    {
        Bureaucrat* juan = new Bureaucrat("Juan", 100);
        Bureaucrat* copy = new Bureaucrat(*juan);

        std::cout << "Juan:" << std::endl;
        std::cout << *juan << std::endl;

        std::cout << "Copy:" << std::endl;
        std::cout << *copy << std::endl;

        delete juan;
        delete copy;
    }

    std::cout << std::endl;
    std::cout << "=== Equal operator ===" << std::endl;
    {
        Bureaucrat* juan = new Bureaucrat("Juan", 100);
        Bureaucrat* copy = new Bureaucrat();

        std::cout << "Juan:" << std::endl;
        std::cout << *juan << std::endl;

        std::cout << "Copy:" << std::endl;
        std::cout << *copy << std::endl;

        *copy = *juan;

        std::cout << "After equal operator:" << std::endl;
        std::cout << *copy << std::endl;

        delete juan;
        delete copy;
    }

    std::cout << std::endl;
    std::cout << "=== Destructor ===" << std::endl;
    {
        Bureaucrat* juan = new Bureaucrat("Juan", 100);
        delete juan;
    }

    std::cout << std::endl;
    std::cout << "=== Destructor with exception ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 0);
            delete juan;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            std::cout << "Exception Bureaucrat::GradeTooHighException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Destructor with exception ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 151);
            delete juan;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            std::cout << "Exception Bureaucrat::GradeTooLowException has ocurred" << std::endl;
            std::cout << ex.what() << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Unexpected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
