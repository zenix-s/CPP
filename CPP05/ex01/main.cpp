#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Form test ===" << std::endl;
    {
        try
        {
            Form form("Form1", 50, 50);
            Bureaucrat bureaucrat("Santiago", 1);
            form.beSigned(bureaucrat);
            std::cout << "Form test - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Form test - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Form test with exception ===" << std::endl;
    {
        try
        {
            Form form("Form2", 0, 50);
            std::cout << "Form test with exception - ko" << std::endl;
        }
        catch (const Form::GradeTooHighException& ex)
        {
            std::cout << "Form test with exception - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Form test with exception - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Form test with exception ===" << std::endl;
    {
        try
        {
            Form form("Form3", 50, 151);
            std::cout << "Form test with exception - ko" << std::endl;
        }
        catch (const Form::GradeTooLowException& ex)
        {
            std::cout << "Form test with exception - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Form test with exception - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Test copy constructor and equal operator ===" << std::endl;
    {
        try
        {
            Form  form("Complex form", 10, 5);
            Form  constructorCopy(form);
            Form* equalCopy = new Form();
            *equalCopy = form;
            delete equalCopy;
            std::cout << "Test copy constructor and equal operator - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Test copy constructor and equal operator - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Let form be signed by a bureaucrat ===" << std::endl;
    {
        try
        {
            Bureaucrat bureaucrat("Santiago", 1);
            Form       form("Form4", 50, 50);
            bureaucrat.signForm(form);
            std::cout << "Let form be signed by a bureaucrat - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Let form be signed by a bureaucrat - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Invalid form signing attempt ===" << std::endl;
    {
        try
        {
            Bureaucrat bureaucrat("Santiago");
            Form       form("Form5", 50, 50);
            bureaucrat.incrementGrade();
            bureaucrat.signForm(form);
            std::cout << "Invalid form signing attempt - ok" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            std::cout << "Invalid form signing attempt - ok" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            std::cout << "Invalid form signing attempt - ok" << std::endl;
        }
        catch (const Form::GradeTooHighException& ex)
        {
            std::cout << "Invalid form signing attempt - ok" << std::endl;
        }
        catch (const Form::GradeTooLowException& ex)
        {
            std::cout << "Invalid form signing attempt - ok" << std::endl;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Invalid form signing attempt - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Bureaucrat and Form at grade 150 (lowest valid) ===" << std::endl;
    {
        try
        {
            Bureaucrat low("Low", 150);
            Form       f("F", 150, 150);
            low.signForm(f);
            std::cout << "Bureaucrat and Form at grade 150 (lowest valid) - ok" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Bureaucrat and Form at grade 150 (lowest valid) - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Already signed form ===" << std::endl;
    {
        try
        {
            Form       f2("F2", 100, 100);
            Bureaucrat b2("B2", 50);
            b2.signForm(f2);
            b2.signForm(f2);
            std::cout << "Already signed form - ok" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Already signed form - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Multiple bureaucrats signing the same form ===" << std::endl;
    {
        try
        {
            Form       f3("F3", 100, 100);
            Bureaucrat b3a("B3a", 100);
            Bureaucrat b3b("B3b", 99);
            b3a.signForm(f3);
            b3b.signForm(f3);
            std::cout << "Multiple bureaucrats signing the same form - ok" << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << "Multiple bureaucrats signing the same form - ko" << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "=== Increment at grade 1 and decrement at grade 150 ===" << std::endl;
    {
        bool test1_ok = false;
        bool test2_ok = false;

        try
        {
            Bureaucrat top("Top", 1);
            top.incrementGrade();
        }
        catch (const std::exception& e)
        {
            test1_ok = true;
        }
        
        try
        {
            Bureaucrat bottom("Bottom", 150);
            bottom.decrementGrade();
        }
        catch (const std::exception& e)
        {
            test2_ok = true;
        }

        if (test1_ok && test2_ok)
            std::cout << "Increment at grade 1 and decrement at grade 150 - ok" << std::endl;
        else
            std::cout << "Increment at grade 1 and decrement at grade 150 - ko" << std::endl;
    }

    return 0;
}