#include "Bureaucrat.hpp"
#include "Logger.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    Logger::printLineJunp();
    Logger::printTitle("ShrubberyCreationForm test");
    {
        ShrubberyCreationForm form("garden");
        std::cout << form << std::endl;

        Logger::printComment("Sign the form");
        Bureaucrat bureaucrat("Santiago", 1);
        std::cout << bureaucrat << std::endl;

        form.beSigned(bureaucrat);

        Logger::printComment("Form new status");
        std::cout << form << std::endl;

        Logger::printComment("Execute the form");
        bureaucrat.executeForm(form);
    }

    Logger::printLineJunp();
    Logger::printTitle("RobotomyRequestForm test");
    {
        RobotomyRequestForm form("Bender");
        Bureaucrat          bureaucrat("Fry", 45);

        form.beSigned(bureaucrat);
        Logger::printComment("Executing robotomy (should be random):");
        for (int i = 0; i < 4; ++i)
            bureaucrat.executeForm(form);
    }

    Logger::printLineJunp();
    Logger::printTitle("PresidentialPardonForm test");
    {
        PresidentialPardonForm form("Ford Prefect");
        Bureaucrat             president("Zaphod", 1);

        form.beSigned(president);
        president.executeForm(form);
    }

    Logger::printLineJunp();
    Logger::printTitle("Test copy constructor and assignment operator");
    {
        ShrubberyCreationForm form("yard");
        ShrubberyCreationForm constructorCopy(form);
        ShrubberyCreationForm assignedCopy("dummy");
        assignedCopy = form;

        Logger::printComment("Original form:");
        std::cout << form << std::endl;
        Logger::printComment("Copy constructor:");
        std::cout << constructorCopy << std::endl;
        Logger::printComment("Assignment operator:");
        std::cout << assignedCopy << std::endl;
    }

    Logger::printLineJunp();
    Logger::printTitle("Edge Case: Not signed exception");
    {
        RobotomyRequestForm form("Leela");
        Bureaucrat          b("Hermes", 1);
        try
        {
            b.executeForm(form);
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Expected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Edge Case: Grade too low to sign or execute");
    {
        ShrubberyCreationForm form("park");
        Bureaucrat            low("Low", 150);
        try
        {
            low.signForm(form);
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Expected exception (sign):");
            Logger::printError(ex.what());
        }
        Bureaucrat execLow("ExecLow", 150);
        Bureaucrat signer("Signer", 1);
        form.beSigned(signer);
        try
        {
            execLow.executeForm(form);
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Expected exception (execute):");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Self-assignment for Bureaucrat and Form");
    {
        Bureaucrat b("Selfie", 42);
        b = b;
        std::cout << "Self-assigned bureaucrat: " << b << std::endl;

        RobotomyRequestForm f("Target");
        f = f;
        std::cout << "Self-assigned form: " << f << std::endl;
    }
}
