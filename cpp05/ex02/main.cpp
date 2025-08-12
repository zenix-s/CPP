#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl;
    std::cout << "=== ShrubberyCreationForm test ===" << std::endl;
    {
        ShrubberyCreationForm form("garden");
        std::cout << form << std::endl;

        std::cout << "Sign the form" << std::endl;
        Bureaucrat bureaucrat("Santiago", 1);
        std::cout << bureaucrat << std::endl;

        form.beSigned(bureaucrat);

        std::cout << "Form new status" << std::endl;
        std::cout << form << std::endl;

        std::cout << "Execute the form" << std::endl;
        bureaucrat.executeForm(form);
    }

    std::cout << std::endl;
    std::cout << "=== RobotomyRequestForm test ===" << std::endl;
    {
        RobotomyRequestForm form("Bender");
        Bureaucrat          bureaucrat("Fry", 45);

        form.beSigned(bureaucrat);
        std::cout << "Executing robotomy (should be random):" << std::endl;
        for (int i = 0; i < 4; ++i)
            bureaucrat.executeForm(form);
    }

    std::cout << std::endl;
    std::cout << "=== PresidentialPardonForm test ===" << std::endl;
    {
        PresidentialPardonForm form("Ford Prefect");
        Bureaucrat             president("Zaphod", 1);

        form.beSigned(president);
        president.executeForm(form);
    }

    std::cout << std::endl;
    std::cout << "=== Test copy constructor and assignment operator ===" << std::endl;
    {
        ShrubberyCreationForm form("yard");
        ShrubberyCreationForm constructorCopy(form);
        ShrubberyCreationForm assignedCopy("dummy");
        assignedCopy = form;

        std::cout << "Original form:" << std::endl;
        std::cout << form << std::endl;
        std::cout << "Copy constructor:" << std::endl;
        std::cout << constructorCopy << std::endl;
        std::cout << "Assignment operator:" << std::endl;
        std::cout << assignedCopy << std::endl;
    }

    std::cout << std::endl;
    std::cout << "=== Edge Case: Not signed exception ===" << std::endl;
    {
        RobotomyRequestForm form("Leela");
        Bureaucrat          b("Hermes", 1);
        try
        {
            b.executeForm(form);
        }
        catch (const std::exception& ex)
        {
            std::cout << "Expected exception:" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Edge Case: Grade too low to sign or execute ===" << std::endl;
    {
        ShrubberyCreationForm form("park");
        Bureaucrat            low("Low", 150);
        try
        {
            low.signForm(form);
        }
        catch (const std::exception& ex)
        {
            std::cout << "Expected exception (sign):" << std::endl;
            std::cout << ex.what() << std::endl;
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
            std::cout << "Expected exception (execute):" << std::endl;
            std::cout << ex.what() << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Self-assignment for Bureaucrat and Form ===" << std::endl;
    {
        Bureaucrat b("Selfie", 42);
        b = b;
        std::cout << "Self-assigned bureaucrat: " << b << std::endl;

        RobotomyRequestForm f("Target");
        f = f;
        std::cout << "Self-assigned form: " << f << std::endl;
    }
}
