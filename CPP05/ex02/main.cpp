#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== ShrubberyCreationForm test ===" << std::endl;
    {
        try
        {
            ShrubberyCreationForm form("garden");
            Bureaucrat bureaucrat("Santiago", 1);
            form.beSigned(bureaucrat);
            bureaucrat.executeForm(form);
            std::cout << "ShrubberyCreationForm test - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "ShrubberyCreationForm test - ko" << std::endl;
        }
    }

    std::cout << "=== RobotomyRequestForm test ===" << std::endl;
    {
        try
        {
            RobotomyRequestForm form("Bender");
            Bureaucrat          bureaucrat("Fry", 45);
            form.beSigned(bureaucrat);
            for (int i = 0; i < 4; ++i)
                bureaucrat.executeForm(form);
            std::cout << "RobotomyRequestForm test - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "RobotomyRequestForm test - ko" << std::endl;
        }
    }

    std::cout << "=== PresidentialPardonForm test ===" << std::endl;
    {
        try
        {
            PresidentialPardonForm form("Ford Prefect");
            Bureaucrat             president("Zaphod", 1);
            form.beSigned(president);
            president.executeForm(form);
            std::cout << "PresidentialPardonForm test - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "PresidentialPardonForm test - ko" << std::endl;
        }
    }

    std::cout << "=== Test copy constructor and assignment operator ===" << std::endl;
    {
        try
        {
            ShrubberyCreationForm form("yard");
            ShrubberyCreationForm constructorCopy(form);
            ShrubberyCreationForm assignedCopy("dummy");
            assignedCopy = form;
            std::cout << "Test copy constructor and assignment operator - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Test copy constructor and assignment operator - ko" << std::endl;
        }
    }

    std::cout << "=== Not signed exception ===" << std::endl;
    {
        try
        {
            RobotomyRequestForm form("Leela");
            Bureaucrat          b("Hermes", 1);
            form.execute(b);
            std::cout << "Not signed exception - ko" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Not signed exception - ok" << std::endl;
        }
    }

    std::cout << "=== Grade too low to sign or execute ===" << std::endl;
    {
        bool sign_test_ok = false;
        bool exec_test_ok = false;

        try
        {
            ShrubberyCreationForm form("park");
            Bureaucrat            low("Low", 150);
            form.beSigned(low);
        }
        catch (const std::exception& ex)
        {
            sign_test_ok = true;
        }

        try
        {
            ShrubberyCreationForm form2("park2");
            Bureaucrat            execLow("ExecLow", 150);
            Bureaucrat            signer("Signer", 1);
            form2.beSigned(signer);
            form2.execute(execLow);
        }
        catch (const std::exception& ex)
        {
            exec_test_ok = true;
        }

        if (sign_test_ok && exec_test_ok)
            std::cout << "Grade too low to sign or execute - ok" << std::endl;
        else
            std::cout << "Grade too low to sign or execute - ko" << std::endl;
    }

    return 0;
}