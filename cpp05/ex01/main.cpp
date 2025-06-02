#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Logger.hpp"
#include <iostream>

int main()
{
    Logger::printLineJunp();
    Logger::printTitle("Form test");
    {
        Form form("Form1", 50, 50);
        std::cout << form << std::endl;

        Logger::printComment("Sign the contract");
        Bureaucrat bureaucrat("Santiago", 1);
        std::cout << bureaucrat << std::endl;

        form.beSigned(bureaucrat);

        Logger::printComment("Form new status");
        std::cout << form << std::endl;
    }

    Logger::printLineJunp();
    Logger::printTitle("Form test with exception");
    {
        try
        {
            Form form("Form2", 0, 50);
            std::cout << form << std::endl;
        }
        catch (const Form::GradeTooHighException& ex)
        {
            Logger::printError("Exception Form::GradeTooHighException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Form test with exception");
    {
        try
        {
            Form form("Form3", 50, 151);
            std::cout << form << std::endl;
        }
        catch (const Form::GradeTooLowException& ex)
        {
            Logger::printError("Exception Form::GradeTooLowException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Test copy constructor and equal operator");
    {
        Form  form("Complex form", 10, 5);
        Form  constructorCopy(form);
        Form* equalCopy = new Form();

        *equalCopy = form;

        Logger::printComment("Original form:");
        std::cout << form << std::endl;
        Logger::printComment("Copy constructor:");
        std::cout << constructorCopy << std::endl;
        Logger::printComment("Equal operator(Constant members should not change):");
        std::cout << *equalCopy << std::endl;
    }

    Logger::printLineJunp();
    Logger::printTitle("Let form be signed by a bureaucrat");
    {
        Bureaucrat bureaucrat("Santiago", 1);
        Form       form("Form4", 50, 50);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);

        std::cout << "After signing:" << std::endl;
        std::cout << form << std::endl;
    }

    Logger::printLineJunp();
    Logger::printTitle("Invalid form signing attempt");
    {
        Bureaucrat bureaucrat("Santiago");
        Form       form("Form5", 50, 50);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        try
        {
            bureaucrat.incrementGrade(); // Raise the grade to 0
            bureaucrat.signForm(form);
        }
        catch (const Bureaucrat::GradeTooHighException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooHighException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const Bureaucrat::GradeTooLowException& ex)
        {
            Logger::printError("Exception Bureaucrat::GradeTooLowException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const Form::GradeTooHighException& ex)
        {
            Logger::printError("Exception Form::GradeTooHighException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const Form::GradeTooLowException& ex)
        {
            Logger::printError("Exception Form::GradeTooLowException has ocurred");
            Logger::printError(ex.what());
        }
        catch (const std::exception& ex)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(ex.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Edge Case: Bureaucrat and Form at grade 150 (lowest valid)");
    {
        try
        {
            Bureaucrat low("Low", 150);
            Form       f("F", 150, 150);
            std::cout << low << std::endl;
            std::cout << f << std::endl;
            low.signForm(f); // Should succeed
            std::cout << "After signing: " << f << std::endl;
        }
        catch (const std::exception& e)
        {
            Logger::printError("Unexpected exception:");
            Logger::printError(e.what());
        }
    }

    Logger::printLineJunp();
    Logger::printTitle("Edge Case: Already signed form");
    {
        Form       f2("F2", 100, 100);
        Bureaucrat b2("B2", 50);
        b2.signForm(f2); // Should sign
        b2.signForm(f2); // Should do nothing or log, but not throw
        std::cout << "Form signed status: " << (f2.getIsSigned() ? "signed" : "not signed") << std::endl;
    }

    Logger::printLineJunp();
    Logger::printTitle("Edge Case: Multiple bureaucrats signing the same form");
    {
        Form       f3("F3", 100, 100);
        Bureaucrat b3a("B3a", 100);
        Bureaucrat b3b("B3b", 99);
        b3a.signForm(f3); // Should sign
        b3b.signForm(f3); // Should do nothing or log, but not throw
        std::cout << "Form signed status: " << (f3.getIsSigned() ? "signed" : "not signed") << std::endl;
    }

    Logger::printLineJunp();
    Logger::printTitle("Edge Case: Self-assignment for Form and Bureaucrat");
    {
        Form f4("F4", 50, 50);
        f4 = f4; // Self-assignment
        std::cout << "Self-assigned form: " << f4 << std::endl;

        Bureaucrat b4("B4", 42);
        b4 = b4; // Self-assignment
        std::cout << "Self-assigned bureaucrat: " << b4 << std::endl;
    }

    Logger::printLineJunp();
    Logger::printTitle("Edge Case: Increment at grade 1 and decrement at grade 150");
    {
        try
        {
            Bureaucrat top("Top", 1);
            top.incrementGrade(); // Should throw
        }
        catch (const std::exception& e)
        {
            Logger::printError("Caught expected exception (increment at grade 1):");
            Logger::printError(e.what());
        }
        try
        {
            Bureaucrat bottom("Bottom", 150);
            bottom.decrementGrade(); // Should throw
        }
        catch (const std::exception& e)
        {
            Logger::printError("Caught expected exception (decrement at grade 150):");
            Logger::printError(e.what());
        }
    }
}
