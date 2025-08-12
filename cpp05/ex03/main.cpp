#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Intern creates a form ===" << std::endl;
    {
        try
        {
            Intern intern;
            AForm* form1 = intern.makeForm("robotomy request", "Bender");
            if (form1)
            {
                delete form1;
            }
            AForm* form2 = intern.makeForm("presidential pardon", "Zaphod");
            if (form2)
            {
                delete form2;
            }
            AForm* form3 = intern.makeForm("shrubbery creation", "Earth");
            if (form3)
            {
                delete form3;
            }
            AForm* form4 = intern.makeForm("unknown form", "Unknown");
            if (form4)
            {
                delete form4;
            }
            std::cout << "Intern creates a form - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Intern creates a form - ko" << std::endl;
        }
    }

    std::cout << "=== Test intern with valid forms ===" << std::endl;
    {
        try
        {
            Intern intern;
            Bureaucrat boss("Boss", 1);
            AForm* robotomy = intern.makeForm("robotomy request", "Alice");
            if (robotomy)
            {
                boss.signForm(*robotomy);
                boss.executeForm(*robotomy);
                delete robotomy;
            }
            AForm* pardon = intern.makeForm("presidential pardon", "Bob");
            if (pardon)
            {
                boss.signForm(*pardon);
                boss.executeForm(*pardon);
                delete pardon;
            }
            AForm* shrubbery = intern.makeForm("shrubbery creation", "garden");
            if (shrubbery)
            {
                boss.signForm(*shrubbery);
                boss.executeForm(*shrubbery);
                delete shrubbery;
            }
            std::cout << "Test intern with valid forms - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Test intern with valid forms - ko" << std::endl;
        }
    }

    std::cout << "=== Test intern with invalid form ===" << std::endl;
    {
        try
        {
            Intern intern;
            AForm* invalidForm = intern.makeForm("invalid form type", "target");
            if (invalidForm == NULL)
            {
                std::cout << "Test intern with invalid form - ok" << std::endl;
            }
            else
            {
                std::cout << "Test intern with invalid form - ko" << std::endl;
                delete invalidForm;
            }
        }
        catch (const std::exception& ex)
        {
            std::cout << "Test intern with invalid form - ko" << std::endl;
        }
    }

    std::cout << "=== Test intern copy constructor and assignment ===" << std::endl;
    {
        try
        {
            Intern intern1;
            Intern intern2(intern1);
            Intern intern3;
            intern3 = intern1;
            AForm* form1 = intern1.makeForm("robotomy request", "Target1");
            AForm* form2 = intern2.makeForm("robotomy request", "Target2");
            AForm* form3 = intern3.makeForm("robotomy request", "Target3");
            bool test_ok = true;
            if (form1) delete form1;
            else test_ok = false;
            if (form2) delete form2;
            else test_ok = false;
            if (form3) delete form3;
            else test_ok = false;
            if (test_ok)
                std::cout << "Test intern copy constructor and assignment - ok" << std::endl;
            else
                std::cout << "Test intern copy constructor and assignment - ko" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Test intern copy constructor and assignment - ko" << std::endl;
        }
    }

    std::cout << "=== Empty strings ===" << std::endl;
    {
        try
        {
            Intern intern;
            AForm* form1 = intern.makeForm("", "target");
            AForm* form2 = intern.makeForm("robotomy request", "");
            bool test_ok = true;
            if (form1) 
            {
                delete form1;
                test_ok = false;
            }
            if (form2)
            {
                delete form2;
            }
            if (test_ok)
                std::cout << "Empty strings - ok" << std::endl;
            else
                std::cout << "Empty strings - ko" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Empty strings - ok" << std::endl;
        }
    }

    return 0;
}