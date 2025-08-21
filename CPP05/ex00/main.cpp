#include <cstdlib>
#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "=== Default constructor ===" << std::endl;
    {
        try 
        {
            Bureaucrat* steve = new Bureaucrat();
            delete steve;
            std::cout << "Default constructor - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Default constructor - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Name constructor ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan");
            delete juan;
            std::cout << "Name constructor - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Name constructor - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Full constructor ===" << std::endl;
    {
        try
        {
            Bureaucrat* santiago = new Bureaucrat("Santiago", 1);
            delete santiago;
            std::cout << "Full constructor - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Full constructor - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Full constructor grade above 1 ===" << std::endl;
    {
        try
        {
            Bureaucrat* santiago = new Bureaucrat("Santiago", 0);
            delete santiago;
            std::cout << "Full constructor grade above 1 - ko" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            std::cout << "Full constructor grade above 1 - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Full constructor grade above 1 - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Full constructor grade below 150 ===" << std::endl;
    {
        try
        {
            Bureaucrat* santiago = new Bureaucrat("Santiago", 151);
            delete santiago;
            std::cout << "Full constructor grade below 150 - ko" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            std::cout << "Full constructor grade below 150 - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Full constructor grade below 150 - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Increment grade, works normal ===" << std::endl;
    {
        try
        {
            Bureaucrat* pablo = new Bureaucrat("Pablo", 2);
            pablo->incrementGrade();
            delete pablo;
            std::cout << "Increment grade, works normal - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Increment grade, works normal - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Decrement grade, works normal ===" << std::endl;
    {
        try
        {
            Bureaucrat* pedro = new Bureaucrat("Pedro", 1);
            pedro->decrementGrade();
            delete pedro;
            std::cout << "Decrement grade, works normal - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Decrement grade, works normal - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Increment grade, throws exception when out of bounds ===" << std::endl;
    {
        Bureaucrat* pedro = new Bureaucrat("Pedro", 1);
        try
        {
            pedro->incrementGrade();
            delete pedro;
            std::cout << "Increment grade, throws exception when out of bounds - ko" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            delete pedro;
            std::cout << "Increment grade, throws exception when out of bounds - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            delete pedro;
            std::cout << "Increment grade, throws exception when out of bounds - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Decrement grade, throws exception when out of bounds ===" << std::endl;
    {
        Bureaucrat* pedro = new Bureaucrat("Pedro", 150);
        try
        {
            pedro->decrementGrade();
            delete pedro;
            std::cout << "Decrement grade, throws exception when out of bounds - ko" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            delete pedro;
            std::cout << "Decrement grade, throws exception when out of bounds - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            delete pedro;
            std::cout << "Decrement grade, throws exception when out of bounds - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Copy constructor ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 100);
            Bureaucrat* copy = new Bureaucrat(*juan);
            delete juan;
            delete copy;
            std::cout << "Copy constructor - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Copy constructor - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Equal operator ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 100);
            Bureaucrat* copy = new Bureaucrat();
            *copy = *juan;
            delete juan;
            delete copy;
            std::cout << "Equal operator - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Equal operator - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Destructor ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 100);
            delete juan;
            std::cout << "Destructor - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Destructor - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Destructor with exception ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 0);
            delete juan;
            std::cout << "Destructor with exception - ko" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            std::cout << "Destructor with exception - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Destructor with exception - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Destructor with exception ===" << std::endl;
    {
        try
        {
            Bureaucrat* juan = new Bureaucrat("Juan", 151);
            delete juan;
            std::cout << "Destructor with exception - ko" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            std::cout << "Destructor with exception - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Destructor with exception - ko" << std::endl;
        }
    }

    return EXIT_SUCCESS;
}